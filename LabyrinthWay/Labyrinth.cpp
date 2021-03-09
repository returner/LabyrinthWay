///////////////////////////////////////////////////////////////////////////////
// Labyrinth Data Parser in the GrandSlam Baseball Version 0.97 alpha
// start : 2001년 9월 5일
// end   : 먼훗날 언젠가....
//
///////////////////////////////////////
//         Labyrinth.cpp
//
///////////////////////////////////////
// CParser  - 저장된 파일에서 라인을 읽어 분석해서 데이터 클래스에 저장.
// CCellType - 기본이 되는 데이터 변수 타입 정의클래스
// CCellData - CCellType형 데이터를 억세스 하는 클래스
// CTileToPoint - 타일번호를 좌표로 바꿔주는 클래스.
//
// 제작 : Benedict Amadeus
// email : returner@vertexdigital.com
//         returner@netsgo.com
// This Definition and Declaration files are copyright by Vertex Digital co.Ltd,. limited
//
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Labyrinth.h"

BOOL CCellData::SetAttributes (BOOL bFlags, CCellType cellType)
{
	// bFlags is reserved
	BOOL ret;
	__try
	{
		m_nCellType.ctNumber   = cellType.ctNumber;
		m_nCellType.ctGround   = cellType.ctGround;
		m_nCellType.ctDecision = cellType.ctDecision;
		m_nCellType.ctTime     = cellType.ctTime;

		ret = TRUE;
	}
	__except (1)
	{
		ret = FALSE;
	}

	return ret;
}

CCellType CCellData::GetAttributes()
{
	CCellType tempCellType;

	__try
	{
		tempCellType.ctNumber   = m_nCellType.ctNumber;
		tempCellType.ctGround   = m_nCellType.ctGround;
		tempCellType.ctDecision = m_nCellType.ctDecision;
		tempCellType.ctTime     = m_nCellType.ctTime;
	}
	__except (1)
	{
		tempCellType.ctDecision = NULL;
		tempCellType.ctGround = NULL;
		tempCellType.ctGround = NULL;
		tempCellType.ctTime = NULL;
	}
	
	return tempCellType;
}

CCellData::CCellData()
{
	m_nCellType.ctNumber   = 9;
	m_nCellType.ctGround   = 9;
	m_nCellType.ctDecision = 9;
	m_nCellType.ctTime     = 9;
}

CParser::CParser()
{
	bNewFlag = FALSE;
	m_pCellData = NULL;
	nLineCount = 0;
}

CParser::~CParser()
{
	if (bNewFlag = TRUE)
	{
		delete[] m_pCellData;
		bNewFlag = FALSE;
	}
}

int CParser::GetLineCount (const char * szFileName)
{
	int nC=0;

	FILE * countFile = fopen (szFileName, "r");
	char buffer[20];

	for (int i=0; i < 600000; i++)
	{
		if (fgets (buffer, 20, countFile) == NULL) break;
		nC++;
	}

	fclose (countFile);

	return nC;
}

CCellData * CParser::ParseFile (const char * szFileName)
{
	//파일명을 인자로 받아 CCellData형 배열에 각셀의 데이터를 
	// 저장한뒤 CcellData형 배열의 포인터를 리턴..
	
	bNewFlag = TRUE;
//	int nLineCount = 0;
	CCellType ct;
	nLineCount = this->GetLineCount(szFileName);

	m_pCellData = new CCellData[nLineCount];

	FILE * file = fopen(szFileName, "r");
	char buffer[20];

	for (int i=0; i<nLineCount; i++)
	{
		fgets (buffer, 20, file);   //한줄 읽어서...
		ct = ParseLine(buffer);  // 분석.....을 한뒤에.. 저장함..
		m_pCellData[i].SetAttributes(TRUE, ct);
	}

	fclose(file);

	return m_pCellData;
}

CCellType CParser::ParseLine (char * szLine)
{	CCellType cellType;
	
	int nCount;
	int numberCount, number, ground, decision, time;
	nCount = number = ground = decision = time = 0;

	char wcNumber[8]; //셀번호
	char wcGround[4]; //지면속성
	char wcDecision[4]; //판정
	char wcTime[4]; //시간

	for (int i=0; i<20; i++)
	{
		nCount ++;
		if ( szLine[i] == ':' ) numberCount = nCount;
		if ( szLine[i] == ';' ) ground      = nCount;
		if ( szLine[i] == ',' ) decision    = nCount;
		if ( szLine[i] == '*' ) 
		{
			time = nCount;
			break;
		}
	}

	for (i=0; i<numberCount; i++) //셀 번호.
	{
		wcNumber[i] = szLine[i];
	}
	for (i=numberCount; i<ground; i++) //지면속성
	{
		wcGround[i-numberCount] = szLine[i];
	}
	for (i=ground; i<decision; i++)   //판정
	{
		wcDecision[i-ground] = szLine[i];
	}
	for (i=decision; i<time; i++) //시간.
	{
		wcTime[i-decision] = szLine[i];
	}

	wcNumber[numberCount-1]        = '\0';
	wcGround[ground-numberCount-1] = '\0';
	wcDecision[decision-ground-1]  = '\0';
	wcTime[time-decision-1]        = '\0';

	// char 형을 int형으로 바꿈 (클래스 변수로 type casting)
	int nNumber, nGround, nDecision, nTime;
	nNumber   = atoi ( wcNumber );
	nGround   = atoi ( wcGround );
	nDecision = atoi ( wcDecision );
	nTime     = atoi ( wcTime );

	cellType.ctNumber = nNumber;
	cellType.ctGround = (unsigned short int)nGround;
	cellType.ctDecision = (unsigned short int)nDecision;
	cellType.ctTime = (unsigned short int)nTime;

	return cellType;
}

int CParser::GetLineCount()
{
	// 라인갯수를 담고있는 멤버 nLineCount를 넘겨줌.
	return nLineCount;
}



POINT CParser::NumberToPoint(int tileNumber, int ImageSizeWidth, int tileXsize, int tileYsize)
{
	POINT point;

	int tileHCount; //이미지를 세로로 짜른 갯수
	tileHCount = 0;

	if (tileNumber == 0)
	{
		point.x = 0;
		point.y = 0;
	}
	else if (tileNumber < 0)
	{
		point.x = NULL;
		point.y = NULL;
	}
	else
	{
		tileHCount = ImageSizeWidth / tileXsize;
		point.x = (tileNumber % tileHCount ) * tileXsize;
		point.y = (tileNumber / tileHCount ) * tileYsize;
	}

	return point;
}
