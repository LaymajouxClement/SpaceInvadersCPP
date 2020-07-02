/*
 * CShipRocket.h
 *
 *  Created on: 1 juil. 2020
 *      Author: eleve
 */

#ifndef CSHIPROCKET_H_
#define CSHIPROCKET_H_

#include "CFigure.h"



class CShipRocket : public CFigure{
private:
	static SDL_Texture * c_pTexture;
public:
	CShipRocket();
	CShipRocket(
			int iLocX,
			int iLocY,
			int iWidth,
			int iHeight,
			int fHotRatioX,
			int fHotRatioY,
			int iSpeedX,
			int iSpeedY
	);
	~CShipRocket();

	void Draw() const;
public:
	static void InitGraphic(SDL_Renderer*pRenderer, const char *pImageFileName){
		SDL_Surface * image=IMG_Load(pImageFileName);
		if(image==nullptr)return;
		c_pTexture=SDL_CreateTextureFromSurface(pRenderer,image);
		SDL_FreeSurface(image);
	}
	static void ReleaseGraphic(void){
		if(c_pTexture){
			SDL_DestroyTexture(c_pTexture);
			c_pTexture = nullptr;
		}
		return;
	}

	static CShipRocket*DeleteFunc(CShipRocket*pShipRocket){
		delete pShipRocket;
		return nullptr;
	}

	static CShipRocket*DrawFunc(CShipRocket*pShipRocket, void*pParam){
		pShipRocket->Draw();
		return pShipRocket;
	}

	static CShipRocket*MoveFunc(CShipRocket*pShipRocket, void*pParam){
		pShipRocket->Move();
		return pShipRocket;
	}
};
#endif /* CSHIPROCKET_H_ */
