// Labyrinth Data Parser in the GrandSlam Baseball Version 0.97 alpha
// start : 2001년 9월 4일
// end   : 먼훗날 언젠가....
//
///////////////////////////////////////
//         Labyrinth.h
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

#ifndef __LABYRINTH_GRANDSLAM_H
#define __lABYRINTH_GRANDSLAM_H

//////////////////////////////////////////////////////////
// 기본적인 타입정의 클래스
//
class CCellType
{
public:
	// 셀번호
	unsigned int ctNumber;

	// 지면속성
	unsigned short int ctGround;

	// 판단
	unsigned short int ctDecision;

	// 시간..
	unsigned short int ctTime;
};

//////////////////////////////////////////////////////////
// 속성정보 등이 저장되는 클래스.
//
class CCellData
{
public:
	// 속성값 저장
	BOOL SetAttributes (BOOL bFlags, CCellType cellType);

	// 속성값 얻음
	CCellType GetAttributes ();
	
	// constructor
	CCellData();
protected:
	// 속성들..
	CCellType m_nCellType;
};

///////////////////////////////////////////
// 파일읽고 분석 라인번호 구하는 클래스..
//
class CParser
{
public:
	// 라인갯수 얻음
	int GetLineCount();

	// 데이터 파싱
	CCellData * ParseFile (const wchar_t * szFileName);

	// 셀번호를 POINT 구조체로...
	POINT NumberToPoint (int tileNumber, int ImageSizeWidth, 
				         int tileXsize, int tileYsize);
	
	// constructor
	CParser ();

	// destructor
	~CParser ();
protected:
	// 라인갯수
	int nLineCount;

	// 라인갯수 구함.
	int GetLineCount(const wchar_t * szFileName);
	
	// 배열이 할당 되었는지 안된건지 알아보는 플래그
	BOOL bNewFlag;

	// 한줄 분석
	CCellType ParseLine (wchar_t * szLine);
	
	// CellData의 포인터
	CCellData * m_pCellData;
};

#endif
