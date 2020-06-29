/*
 * CApp.h
 *
 *  Created on: 29 juin 2020
 *      Author: eleve
 */
#ifndef CAPP_H_
#define CAPP_H_

#include <SDL2/SDL.h>
#include "CFigure.h"
#include "CShip.h"

class CApp {
private:
	Uint32				m_uStatus;
	SDL_Window 	 	*	m_pWindow;
	Uint32				m_uWindowID;
	SDL_Renderer	*	m_pRenderer;
	SDL_Texture	 	*	m_pTextureBkgnd;

	CShip 				m_ship{200,50,50,50,10,10,0,0};

public:
	CApp();
	~CApp();

	void Run(void*pParam);

	bool IsInitiated() const;
};

#endif /* CAPP_H_ */
