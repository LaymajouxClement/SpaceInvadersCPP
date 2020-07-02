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

#include "CContainer.h"

class CApp {
private:
	Uint32				m_uStatus;
	SDL_Window		*	m_pWindow;
	Uint32				m_uWindowID;
	SDL_Renderer	*	m_pRenderer;
	SDL_TimerID			m_nTimerID;
	SDL_Texture		*	m_pBkgndTexture;

	CShip			*	m_pShip;

	CContainer		*	m_pAliens;
	CContainer		*   m_pShipRockets;


public:
	CApp();
	~CApp();

private:
	void Run(void*pParam);
	bool IsInitiated() const; // il s'agit ici d'un "getter"

	static Uint32 AnimateCallback (Uint32 interval, void*param);
};

#endif /* CAPP_H_ */
