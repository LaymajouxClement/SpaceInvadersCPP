/*
 * CContainer.cpp
 *
 *  Created on: 1 juil. 2020
 *      Author: eleve
 */

#include "CContainer.h"
#include <cassert>

#ifdef _DEBUG_
#include <iostream>
using namespace std;
#define _dbgTrack(msg)	cout << msg
#else
#define _dbgTrack(msg)
#endif


/********************** CNode Component Implementation Section ***********************/

CContainer::CNode::CNode() :
		m_pPrev(nullptr),
		m_pNext(nullptr),
		m_pElem(nullptr)
{
	_dbgTrack( << "CNode::CNode() #" << this << endl);
}

CContainer::CNode::CNode(CNode*pPrev, CNode*pNext, void*pElem) :
		m_pPrev(pPrev),
		m_pNext(pNext),
		m_pElem(pElem)
{
	if (m_pPrev) { m_pPrev->m_pNext = this; }
	if (m_pNext) { m_pNext->m_pPrev = this; }

	_dbgTrack( << "CNode::CNode(CNode*pPrev, CNode*pNext, void*pElem) #" << this << endl);
}

CContainer::CNode::~CNode() {
	if (m_pPrev) { m_pPrev->m_pNext = m_pNext; }
	if (m_pNext) { m_pNext->m_pPrev = m_pPrev; }

	_dbgTrack(<< "CNode::~CNode() #" << this << endl);

}

/********************** CContainer Component Implementation Section ***********************/
CContainer::CContainer() :
		m_pHead(nullptr),
		m_pTail(nullptr),
		m_nCard(0),
		m_pDeleteFunc(nullptr)
{
	_dbgTrack( << "CContainer::CContainer() #" << this << endl);
}

CContainer::CContainer(t_ptfV pDeleteFunc) :
		CContainer()
{
	_dbgTrack(<< "CContainer::CContainer(t_ptfV pDeleteFunc) #" << this << endl);
	m_pDeleteFunc = pDeleteFunc;
}

CContainer::~CContainer() {
	//if(!this) return;
	_dbgTrack( << "CContainer::~CContainer() #" << this << endl);
	while(m_pHead) {
		m_pTail = m_pHead;
		m_pHead = m_pHead->m_pNext;
		m_pDeleteFunc(m_pTail->m_pElem);
		delete m_pTail;
		m_nCard--;
	}

	assert(m_nCard == 0);
}

void* CContainer::Pushback(void*pElem) {
	//cout << "CContainer::Pushback()" << endl;
	if (m_nCard == 0) {
		assert(m_pHead == nullptr);
		assert(m_pTail == nullptr);
		m_pHead = m_pTail = new CNode(nullptr, nullptr, pElem);
	}
	else {
		m_pTail = new CNode(m_pTail, nullptr, pElem);
	}
	assert(m_pTail->m_pElem == pElem);
	m_nCard++;
	return pElem;
}

int CContainer::Card() const { return m_nCard; }

void * CContainer::Parse(t_ptfVV pParseFunc,void*pParam) {
	_dbgTrack( << "CContainer::Parse()" << endl);
	CNode * pScan{m_pHead};

	while(pScan){
		if(!pParseFunc(pScan->m_pElem, pParam)) return pScan->m_pElem;
		pScan = pScan->m_pNext;
	}
	return nullptr;
}
