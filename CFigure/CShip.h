/*
 * CShip.h
 *
 *  Created on: 29 juin 2020
 *      Author: eleve
 */

#ifndef CSHIP_H_
#define CSHIP_H_

#include <CFigure.h>

class CShip : public CFigure {
private:
	static SDL_Texture * c_pTexture;
public:
	CShip();
	CShip(
				int iLocX,
				int iLocY,
				int iWidth,
				int iHeight,
				int iHotRatioX,
				int iHotRatioY,
				int iSpeedX,
				int iSpeedY
		);
	~CShip();
	void Draw()const;
public:
	static void InitGraphic(SDL_Renderer * pRenderer , const char * pImageFileName){
		SDL_Surface * image=IMG_Load(pImageFileName);
		if(image==NULL) return;
		c_pTexture = SDL_CreateTextureFromSurface(pRenderer, image);
		SDL_FreeSurface(image);
	}
	static void ReleaseGraphic(){
		if(c_pTexture){
			SDL_DestroyTexture(c_pTexture);
			c_pTexture = nullptr;
		}
	}
};

#endif /* CSHIP_H_ */
