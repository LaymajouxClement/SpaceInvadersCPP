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

class CFigure {
private:	//déclaration des attributs statiques : attributs de classe
	static SDL_Renderer * 	c_pRenderer;
	static SDL_Rect		*	c_gameArea;


protected:		// Pour pouvoir être hétité par les classes filles  (classes dérivées )
	SDL_Rect	m_frame;
	SDL_Point	m_hotPointRatio;
	SDL_Point	m_speed;


public:
	CFigure();		//Constructeur par défaut(aucun param)
	CFigure(
			int iLocX,
			int iLocY,
			int iWidth,
			int iHeight,
			int iHotRatioX,
			int iHotRatioY,
			int iSpeedX,
			int iSpeedY
	);

	~CFigure();		//Destructeur par défaut(aucun param)

	int Move();
	int Move(int iX,int iY);
	void Draw(SDL_Texture*pTexture) const;

public:		//déclaration des méthodes statiques
	static void InitGraphic(SDL_Renderer*pRenderer,const SDL_Rect*pGameArea){
		c_pRenderer = pRenderer;
		SDL_memcpy(&c_gameArea,pGameArea,sizeof(SDL_Rect));
	}
};

#endif /* CFIGURE_H_ */
