/*
 * CApp.cpp
 *
 *  Created on: 29 juin 2020
 *      Author: eleve
 */

#include "CApp.h"
#include "app.h"
#include <iostream>
using namespace std;

enum STATUS : Uint32{
	ST_ALL_CLEARED 	= 0x00000000,
	ST_ALL_SETTED 	= 0xFFFFFFFF,
	ST_APP_INITIED	= 0x00000001,
};

CApp::CApp() :
		m_uStatus(0),
		m_pWindow(nullptr),
		m_uWindowID(-1),
		m_pRenderer(nullptr),
		m_pTextureBkgnd(nullptr)
{
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)<0){
		cerr << "SDL_Init() failed with error:" << SDL_GetError() << endl;
		return;
	}

	m_pWindow = SDL_CreateWindow(
		MAIN_WINDOW_TITLE,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		MAIN_WINDOW_WIDTH,
		MAIN_WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if(m_pWindow == nullptr){
		cerr << "DL_CreateWindow() failed with error:" << SDL_GetError() << endl;
		return;
	}
	m_uWindowID = SDL_GetWindowID(m_pWindow);

	m_pRenderer = SDL_CreateRenderer(m_pWindow,-1, SDL_RENDERER_ACCELERATED);
	if (m_pRenderer == NULL) {
		fprintf(stderr, "Failed to create accelerated renderer.\n");
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_SOFTWARE);
		if (m_pRenderer == NULL) {
			fprintf(stderr, "Failed to create software renderer.\n");
			return;
		}
		fprintf(stderr, "Software renderer created instead!\n");
	}

	/*------------------INIT CFigure Class---------------------*/
	SDL_Rect gameArea{
		MAIN_WINDOW_PADDING_HRZ,
		MAIN_WINDOW_PADDING_TOP,
		MAIN_WINDOW_WIDTH-2*(MAIN_WINDOW_PADDING_HRZ),
		MAIN_WINDOW_HEIGHT - (MAIN_WINDOW_PADDING_TOP + MAIN_WINDOW_PADDING_TOP)
	};

	CFigure::InitGraphic(m_pRenderer,&gameArea);

	SDL_Surface* pImageBkgnd=IMG_Load(MAIN_WINDOW_BACKGROUND_IMAGE);
	if(pImageBkgnd==NULL){
		fprintf(stderr,"Failed to load image: %s\n", SDL_GetError());
	}
	else{
		m_pTextureBkgnd=SDL_CreateTextureFromSurface(m_pRenderer, pImageBkgnd);
		SDL_FreeSurface(pImageBkgnd);
	}
	if(m_pTextureBkgnd){
		SDL_RenderCopy(m_pRenderer, m_pTextureBkgnd, NULL, NULL);
	}


	CShip::InitGraphic(m_pRenderer,SPACESHIP_IMAGE);

	m_ship.Draw();


	cout << "CApp::CApp()" << endl;
	m_uStatus |= ST_APP_INITIED;
	SDL_RenderPresent(m_pRenderer);
	Run(nullptr);
}

CApp::~CApp() {
	CShip::ReleaseGraphic();

	if(m_pRenderer){
		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer = nullptr;
	}

	if(m_pWindow){
		SDL_DestroyWindow(m_pWindow);
		m_pWindow=nullptr;
	}
	SDL_Quit();
	cout << "CApp::~CApp()" << endl;
}

void CApp::Run(void*pParam){
	if(!(m_uStatus & ST_APP_INITIED))return;

	int quit {0};
	SDL_Event event;

	do{
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				quit=1;
				break;
			case SDL_KEYUP:
				if(event.key.keysym.sym==SDLK_ESCAPE){
					quit=1;
				}
				break;
			default:
				break;
			}
		}
	}while(quit!=1);
	cout << "CApp::Run()" << endl;
}

bool CApp::IsInitiated()const {return m_uStatus & ST_APP_INITIED;}


