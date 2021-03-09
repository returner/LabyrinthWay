// Labyrinth Data Parser in the GrandSlam Baseball Version 0.97 alpha
// start : 2001�� 9�� 4��
// end   : ���ʳ� ������....
//
///////////////////////////////////////
//         Labyrinth.h
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

#ifndef __LABYRINTH_GRANDSLAM_H
#define __lABYRINTH_GRANDSLAM_H

//////////////////////////////////////////////////////////
// �⺻���� Ÿ������ Ŭ����
//
class CCellType
{
public:
	// ����ȣ
	unsigned int ctNumber;

	// ����Ӽ�
	unsigned short int ctGround;

	// �Ǵ�
	unsigned short int ctDecision;

	// �ð�..
	unsigned short int ctTime;
};

//////////////////////////////////////////////////////////
// �Ӽ����� ���� ����Ǵ� Ŭ����.
//
class CCellData
{
public:
	// �Ӽ��� ����
	BOOL SetAttributes (BOOL bFlags, CCellType cellType);

	// �Ӽ��� ����
	CCellType GetAttributes ();
	
	// constructor
	CCellData();
protected:
	// �Ӽ���..
	CCellType m_nCellType;
};

///////////////////////////////////////////
// �����а� �м� ���ι�ȣ ���ϴ� Ŭ����..
//
class CParser
{
public:
	// ���ΰ��� ����
	int GetLineCount();

	// ������ �Ľ�
	CCellData * ParseFile (const wchar_t * szFileName);

	// ����ȣ�� POINT ����ü��...
	POINT NumberToPoint (int tileNumber, int ImageSizeWidth, 
				         int tileXsize, int tileYsize);
	
	// constructor
	CParser ();

	// destructor
	~CParser ();
protected:
	// ���ΰ���
	int nLineCount;

	// ���ΰ��� ����.
	int GetLineCount(const wchar_t * szFileName);
	
	// �迭�� �Ҵ� �Ǿ����� �ȵȰ��� �˾ƺ��� �÷���
	BOOL bNewFlag;

	// ���� �м�
	CCellType ParseLine (wchar_t * szLine);
	
	// CellData�� ������
	CCellData * m_pCellData;
};

#endif
