#ifndef _CCOLOR_H
#define _CCOLOR_H

///////////////////////////////////////////
// �뵵 : int������ ���� ���ǽ� ���
// ���̿ܿ� ������ ������ �ʿ��ϸ� �˾Ƽ� ����..

class CColor
{
public:
	CColor();
	~CColor();
	// copy constructor
	CColor(const CColor & pColor);
public:
	int red;
	int green;
	int blue;
};

#endif
