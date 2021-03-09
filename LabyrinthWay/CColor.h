#ifndef _CCOLOR_H
#define _CCOLOR_H

///////////////////////////////////////////
// 용도 : int값으로 색깔 정의시 사용
// 그이외에 정수형 세개가 필요하면 알아서 쓸것..

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
