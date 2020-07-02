/*
 * CAlien.cpp
 *
 *  Created on: 1 juil. 2020
 *      Author: eleve
 */

#include <CAlien.h>
#include <iostream>
using namespace std;
SDL_Texture * CAlien::c_pTexture;

CAlien::CAlien() {
	// TODO Auto-generated constructor stub
		cout << "CAlien::CAlien()" << endl;
}

CAlien::CAlien(
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

CAlien::~CAlien() {
	// TODO Auto-generated destructor stub
	cout << "CAlien::~CAlien()" << endl;
}

void CAlien::Draw() const{
	CFigure::Draw(c_pTexture);
}


