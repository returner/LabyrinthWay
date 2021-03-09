///////////////////////////////////////////////////////////////////////////////
// Labyrinth Data Parser in the GrandSlam Baseball Version 0.97 alpha
// start : 2001�� 9�� 5��
// end   : ���ʳ� ������....
//
///////////////////////////////////////
//         Labyrinth.cpp
//
///////////////////////////////////////
// CParser  - ����� ���Ͽ��� ������ �о� �м��ؼ� ������ Ŭ������ ����.
// CCellType - �⺻�� �Ǵ� ������ ���� Ÿ�� ����Ŭ����
// CCellData - CCellType�� �����͸� �＼�� �ϴ� Ŭ����
// CTileToPoint - Ÿ�Ϲ�ȣ�� ��ǥ�� �ٲ��ִ� Ŭ����.
//
// ���� : Benedict Amadeus
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
	m_nCellType.ctNumber   = 0;
	m_nCellType.ctGround   = 0;
	m_nCellType.ctDecision = 0;
	m_nCellType.ctTime     = 0;
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

int CParser::GetLineCount (const wchar_t * szFileName)
{
	int nC=0;

	FILE * countFile = _wfopen (szFileName, _T("r"));
	wchar_t buffer[20];

	for (int i=0; i < 600000; i++)
	{
		if (fgetws (buffer, 20, countFile) == NULL) break;
		nC++;
	}

	fclose (countFile);

	return nC;
}

CCellData * CParser::ParseFile (const wchar_t * szFileName)
{
	//���ϸ��� ���ڷ� �޾� CCellData�� �迭�� ������ �����͸� 
	// �����ѵ� CcellData�� �迭�� �����͸� ����..
	
	bNewFlag = TRUE;
//	int nLineCount = 0;
	CCellType ct;
	nLineCount = this->GetLineCount(szFileName);

	m_pCellData = new CCellData[nLineCount];

	FILE * file = _wfopen(szFileName, _T("r"));
	wchar_t buffer[20];

	for (int i=0; i<nLineCount; i++)
	{
		fgetws (buffer, 20, file);   //���� �о...
		ct = ParseLine(buffer);  // �м�.....�� �ѵڿ�.. ������..
		m_pCellData[i].SetAttributes(TRUE, ct);
	}

	fclose(file);

	return m_pCellData;
}

CCellType CParser::ParseLine (wchar_t * szLine)
{	CCellType cellType;
	
	int nCount;
	int numberCount, number, ground, decision, time;
	nCount = number = ground = decision = time = 0;

	wchar_t wcNumber[8]; //����ȣ
	wchar_t wcGround[4]; //����Ӽ�
	wchar_t wcDecision[4]; //����
	wchar_t wcTime[4]; //�ð�

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

	for (i=0; i<numberCount; i++) //�� ��ȣ.
	{
		wcNumber[i] = szLine[i];
	}
	for (i=numberCount; i<ground; i++) //����Ӽ�
	{
		wcGround[i-numberCount] = szLine[i];
	}
	for (i=ground; i<decision; i++)   //����
	{
		wcDecision[i-ground] = szLine[i];
	}
	for (i=decision; i<time; i++) //�ð�.
	{
		wcTime[i-decision] = szLine[i];
	}

	wcNumber[numberCount-1]        = '\0';
	wcGround[ground-numberCount-1] = '\0';
	wcDecision[decision-ground-1]  = '\0';
	wcTime[time-decision-1]        = '\0';

	// wchar_t ���� int������ �ٲ� (Ŭ���� ������ type casting)
	int nNumber, nGround, nDecision, nTime;
	nNumber   = _wtoi ( wcNumber );
	nGround   = _wtoi ( wcGround );
	nDecision = _wtoi ( wcDecision );
	nTime     = _wtoi ( wcTime );

	cellType.ctNumber = nNumber;
	cellType.ctGround = (unsigned short int)nGround;
	cellType.ctDecision = (unsigned short int)nDecision;
	cellType.ctTime = (unsigned short int)nTime;

	return cellType;
}

int CParser::GetLineCount()
{
	// ���ΰ����� ����ִ� ��� nLineCount�� �Ѱ���.
	return nLineCount;
}

POINT NumberToPoint (int tileNumber, int ImageSizeWidth, int tileXSize, int tileYSize)
{
	POINT point;

	int tileHCount; //�̹����� ���η� ¥�� ����
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
		tileHCount = ImageSizeWidth / tileXSize;
		point.x = (tileNumber % tileHCount ) * tileXSize;
		point.y = (tileNumber / tileHCount ) * tileYSize;
	}

	return point;
}


