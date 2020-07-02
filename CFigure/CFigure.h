/*
 * CFigure.h
 *
 *  Created on: 29 juin 2020
 *      Author: eleve
 */

#ifndef CFIGURE_H_
#define CFIGURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "macros.h"

class CFigure {
public:
	enum OVF_FLAGS : Uint32 {
		OVF_NONE 	= 0x0000,
		OVF_ALL 	= 0xFFFF,
		OVF_RIGHT 	= 0x0001,
		OVF_TOP 	= 0x0002,
		OVF_LEFT 	= 0x0004,
		OVF_BOT 	= 0x0008
	};

private: // déclaration des attributs statiques
	static SDL_Renderer * 	c_pRenderer;
protected:
	static SDL_Rect			c_gameArea;
	static OVF_FLAGS		c_overflow;



protected: //pour pouvoir être hérité par les classes filles (classes dérivés)
	SDL_Rect        m_frame;
	SDL_Point		m_hotPointRatio;
	SDL_Point		m_speed;



public:
	CFigure(); // Constructeur par défaut (aucun paramètre)
	CFigure(
		int iLocX,
		int iLocY,
		int iWidth,
		int iHeight,
		int iHotRatioX,
		int iHotRatioY,
		int ispeedX,
		int ispeedY
	); // Constructeur surcharge

	~CFigure();

	int Move();
	int Move(int iX, int iY);			//méthode surchargé
	void Draw(SDL_Texture*pTexture) const;					// méthode constante
	SDL_Point GetHotPoint() const;



public: // déclaration des méthodes statiques
	static void InitGraphic(SDL_Renderer*pRenderer, SDL_Rect*pGameArea){
		c_pRenderer = pRenderer;
		SDL_memcpy(&c_gameArea, pGameArea, sizeof(SDL_Rect));
	}
	static void clrOverflows(){
		mBitsClr(OVF_FLAGS, c_overflow, OVF_ALL);
	}
	static OVF_FLAGS GetOverflows(){
		return c_overflow;
	}
};
#endif /* CFIGURE_H_ */

