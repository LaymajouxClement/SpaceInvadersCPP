/*
 * CShip.cpp
 *
 *  Created on: 29 juin 2020
 *      Author: eleve
 */

#include <CShip.h>
#include <iostream>
using namespace std;
SDL_Texture * CShip::c_pTexture;

CShip::CShip() {
	// TODO Auto-generated constructor stub
	cout << "CShip::CShip()" << endl;
}
CShip::CShip(
		int iLocX,
		int iLocY,
		int iWidth,
		int iHeight,
		int iHotRatioX,
		int iHotRatioY,
		int ispeedX,
		int ispeedY
	): // Constructeur surcharge
			CFigure(iLocX, iLocY, iWidth, iHeight, iHotRatioX, iHotRatioY, ispeedX, ispeedY)
{

}

CShip::~CShip() {
	// TODO Auto-generated destructor stub
	cout << "CShip::~CShip()" << endl;
}

void CShip::Draw() const{
	CFigure::Draw(c_pTexture);
}

int CShip::Move(int iLocX,int iLocY){
	iLocY=m_frame.x;
	m_frame.x= iLocX - m_frame.w/2;
	if((m_frame.x<c_gameArea.x)||(m_frame.x + m_frame.w>c_gameArea.x + c_gameArea.w)){
		m_frame.x = iLocY;
	}
	return 0;
}
