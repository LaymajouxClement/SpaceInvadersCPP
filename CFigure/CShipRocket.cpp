/*
 * CShipRocket.cpp
 *
 *  Created on: 1 juil. 2020
 *      Author: eleve
 */

#include <CShipRocket.h>
#include <iostream>
SDL_Texture * CShipRocket::c_pTexture;

CShipRocket::CShipRocket() {
	// TODO Auto-generated constructor stub

}
CShipRocket::CShipRocket(
				int iLocX,
				int iLocY,
				int iWidth,
				int iHeight,
				int fHotRatioX,
				int fHotRatioY,
				int iSpeedX,
				int iSpeedY
			) :
		CFigure(iLocX, iLocY, iWidth, iHeight, fHotRatioX, fHotRatioY, iSpeedX, iSpeedY)
{
	// TODO Auto-generated constructor stub

}
CShipRocket::~CShipRocket() {
	// TODO Auto-generated destructor stub
}

void CShipRocket::Draw() const{
	CFigure::Draw(c_pTexture);
}



