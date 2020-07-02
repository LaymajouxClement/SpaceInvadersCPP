/*
 * CAlien.h
 *
 *  Created on: 1 juil. 2020
 *      Author: eleve
 */

#ifndef CALIEN_H_
#define CALIEN_H_

#include <CFigure.h>

class CAlien : public CFigure {
private:
	static SDL_Texture * c_pTexture;
public:

	CAlien();
	CAlien(
			int iLocX,
			int iLocY,
			int iWidth,
			int iHeight,
			int iHotRatioX,
			int iHotRatioY,
			int ispeedX,
			int ispeedY
		); // Constructeur surcharge
	~CAlien();

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
	static CAlien*DeleteFunc(CAlien*pAlien){
		delete pAlien;
		return nullptr;
	}

	static CAlien*DrawFunc(CAlien*pAlien, void*pParam){
			pAlien->Draw();
			return pAlien;
	}
	static CAlien*MoveFunc(CAlien*pAlien, void*pParam){
			pAlien->Move();
			return pAlien;
	}
	static CAlien*ScrollFunc(CAlien*pAlien, int speedVrt){
			pAlien->m_speed.x *= -1;
			pAlien->m_frame.y += speedVrt;
			CFigure::clrOverflows();
			return pAlien;
	}

};

#endif /* CALIEN_H_ */
