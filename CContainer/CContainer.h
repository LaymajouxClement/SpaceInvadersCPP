#ifndef CCONTAINER_H_
#define CCONTAINER_H_

class CContainer {

	/********************** CNode Component Section ***********************/
	class CNode {
	public:
		CNode * m_pPrev;
		CNode * m_pNext;
		void  * m_pElem;

	public:
		CNode();
		CNode(CNode*pPrev, CNode*pNext, void*pElem);
		~CNode();
	};

/********************** CContainer Component Section ***********************/
public:
	typedef void*(*t_ptfV)(void*);
	typedef void*(*t_ptfVV)(void*, void*);

private:
	CNode    *  m_pHead;
	CNode    * 	m_pTail;
	int 	  	m_nCard;
	t_ptfV 		m_pDeleteFunc;

public:
	CContainer();
	CContainer(t_ptfV pDeleteFunc);
	~CContainer();

	void* Pushback(void*pElem);
	int Card() const;
	void* Parse(t_ptfVV pParseFunc, void*pParam);
};


#endif /* CCONTAINER_H_ */

