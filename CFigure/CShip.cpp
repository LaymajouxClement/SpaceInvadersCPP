/*
 * CShip.cpp
 *
 *  Created on: 29 juin 2020
 *      Author: eleve
 */

#include <CShip.h>
#include <iostream>
using namespace std;

SDL_Texture * CShip::c_pTexture {nullptr};

CShip::CShip() {
	cout << "CShip::CShip()"<< endl;
}

CShip::CShip(
	int iLocX,
	int iLocY,
	int iWidth,
	int iHeight,
	int iHotRatioX,
	int iHotRatioY,
	int iSpeedX,
	int iSpeedY
):
		//Appel du constructeur surchargé é quiv	lent de la classe mère
	CFigure(iLocX,iLocY,iWidth,iHeight,iHotRatioX,iHotRatioY,iSpeedX,iSpeedY)
{

}

CShip::~CShip() {
	cout << "CShip::~CShip()"<< endl;
}

void CShip::Draw()const{
	CFigure::Draw(c_pTexture);
}
