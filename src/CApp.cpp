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
#include "CAlien.h"
#include "CShipRocket.h"

extern CApp theApp;



enum STATUS : Uint32 {
	ST_ALL_CLEARED= 0x00000000,
	ST_ALL_SETTED= 0xFFFFFFFF,
	ST_INIATIED=0x00000001,
};


CApp::CApp() :			//Liste d'initialisation du constructeur
		m_uStatus(0),
		m_pWindow(nullptr),
		m_uWindowID(-1),
		m_pRenderer(nullptr),
		m_nTimerID(-1),
		m_pBkgndTexture(nullptr),
		m_pShip(nullptr),
		m_pAliens(new CContainer((CContainer::t_ptfV)CAlien::DeleteFunc)),
		m_pShipRockets(new CContainer((CContainer::t_ptfV)CShipRocket::DeleteFunc))
{
	// TODO Auto-generated constructor stub
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)<0){
		cerr << "SDL_Init() failed with error:" <<SDL_GetError() <<endl;
	}

	m_pWindow = SDL_CreateWindow(
			MAIN_WINDOW_TITLE_STR,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			MAIN_WINDOW_WIDTH,
			MAIN_WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN
	);

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)<0){
			cerr << "SDL_Init() failed with error:" <<SDL_GetError() <<endl;
			return;
	}
	m_uWindowID = SDL_GetWindowID(m_pWindow);
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (m_pWindow == nullptr) {
			cerr << "Failed to create accelerated renderer" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_SOFTWARE);
			if(m_pRenderer == nullptr){
				cerr<<"Failed to create software renderer!"<<endl;
				return;
			}
			cerr << "Software renderer created instead" << endl;
		}
	/*--------------------------------------------------------------------*/
	SDL_Surface * pBkgndImage=IMG_Load(MAIN_WINDOW_BACKGROUND_IMAGE);
	if(pBkgndImage==nullptr){
		cerr << "Failed to load background : " << SDL_GetError() <<endl;
	}
	else{
		m_pBkgndTexture = SDL_CreateTextureFromSurface(m_pRenderer,pBkgndImage);
		SDL_FreeSurface(pBkgndImage);
	}





	/*---------------------------INIT CFigure clas------------------------*/
	SDL_Rect gameArea {
		MAIN_WINDOW_PADDING_HRZ,
		MAIN_WINDOW_PADDING_TOP,
		MAIN_WINDOW_WIDTH-2*(MAIN_WINDOW_PADDING_HRZ),
		MAIN_WINDOW_HEIGHT-(MAIN_WINDOW_PADDING_TOP + MAIN_WINDOW_PADDING_BOT)
	};
	CFigure::InitGraphic(m_pRenderer, &gameArea);
	CShip::InitGraphic(m_pRenderer, SPACESHIP_IMAGE);
	CAlien::InitGraphic(m_pRenderer, ALIEN_IMAGE);
	CShipRocket::InitGraphic(m_pRenderer, ROCKET_IMAGE);

	m_pShip = new CShip(
		MAIN_WINDOW_WIDTH-SPACESHIP_SIZE/2,
		MAIN_WINDOW_HEIGHT-MAIN_WINDOW_PADDING_BOT-SPACESHIP_SIZE,
		SPACESHIP_SIZE,
		SPACESHIP_SIZE,
		50,
		0,
		0,
		0
	);

	for(int k=0; k<5; k++){
		for(int m=0;m<10;m++){
			m_pAliens->Pushback(
					new CAlien(
							MAIN_WINDOW_PADDING_HRZ + m*(ALIEN_SIZE+5),
							MAIN_WINDOW_PADDING_TOP + k*(ALIEN_SIZE+5),
							ALIEN_SIZE,
							ALIEN_SIZE,
							50,
							100,
							ALIEN_SPEED_HRZ,
							ALIEN_SPEED_VRT


					)
			);
		}
	}

	m_nTimerID = SDL_AddTimer(20, AnimateCallback, &theApp);



	SDL_RenderPresent(m_pRenderer);

	m_uStatus |=ST_INIATIED;
	cout << "CApp::CApp()" << endl;

	Run(nullptr);
}

CApp::~CApp() {
	// TODO Auto-generated destructor stub

	delete m_pShip; m_pShip = nullptr;
	delete m_pAliens; m_pAliens = nullptr;
	delete m_pShipRockets; m_pShipRockets = nullptr;

	CShip::ReleaseGraphic();
	CAlien::ReleaseGraphic();

	SDL_DestroyTexture(m_pBkgndTexture); m_pBkgndTexture = nullptr;
	SDL_RemoveTimer(m_nTimerID); m_nTimerID = -1;

	if(m_pRenderer != nullptr){
		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer=nullptr;
	}

	if(m_pWindow != nullptr){
		SDL_DestroyWindow(m_pWindow);
		m_pWindow=nullptr;
	}
	SDL_Quit();
	cout << "CApp::~CApp()" << endl;
}

void CApp::Run(void*pParam){
	if(!(m_uStatus & ST_INIATIED)) return;
	int quit {0};
	SDL_Event event {0};

	do{
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_MOUSEMOTION:
				m_pShip->Move(event.motion.x, event.motion.y);
				break;
			case SDL_MOUSEBUTTONUP:
				m_pShipRockets->Pushback(
						new CShipRocket(
							m_pShip->GetHotPoint().x-ROCKET_WIDTH/2,
							m_pShip->GetHotPoint().y-ROCKET_HEIGHT,
							ROCKET_WIDTH,
							ROCKET_HEIGHT,
							50,
							100,
							0,
							ALIEN_SPEED_VRT
						)
				);
				break;
			case SDL_QUIT:
				quit=1;
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					quit=1;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

	}while(quit!=1);


	cout << "CApp::Run()" << endl;

}

bool CApp::IsInitiated() const { return m_uStatus & ST_INIATIED; }

Uint32 CApp::AnimateCallback (Uint32 interval, void*param){

	CApp* pTheApp { reinterpret_cast<CApp*>(param)};
	if(pTheApp->m_pBkgndTexture){
		SDL_RenderCopy(pTheApp->m_pRenderer, pTheApp->m_pBkgndTexture, nullptr, nullptr);
	}
	/*---------------------MOVE OBJECT--------------------------*/
	CFigure::clrOverflows();
	pTheApp->m_pAliens->Parse((CContainer::t_ptfVV)CAlien::MoveFunc, nullptr);
	switch(CFigure::GetOverflows()){
	case CFigure::OVF_LEFT:
	case CFigure::OVF_RIGHT:
		pTheApp->m_pAliens->Parse((CContainer::t_ptfVV)CAlien::ScrollFunc, (void*) ALIEN_SCROLL_Y);
		break;
	case CFigure::OVF_BOT:
		break;
	default:
		break;



	}





	/*---------------------DRAW OBJECT--------------------------*/
	pTheApp->m_pShip->Draw();
	pTheApp->m_pAliens->Parse((CContainer::t_ptfVV)CAlien::DrawFunc, nullptr);
	pTheApp->m_pShipRockets->Parse((CContainer::t_ptfVV)CShipRocket::MoveFunc, nullptr);
	pTheApp->m_pShipRockets->Parse((CContainer::t_ptfVV)CShipRocket::DrawFunc, nullptr);

	SDL_RenderPresent(pTheApp->m_pRenderer);
	return interval;
}

