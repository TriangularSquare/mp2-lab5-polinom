#pragma once
#include "list.h"

template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList();
	~THeadList();
	void InsFirst(T elem);
	void DelFirst();
};

template<class T>
inline THeadList<T>::THeadList()
{
	len = 0;
	pHead = new TNode<T>;
	pHead->pNext = pHead;
	pFirst = pLast = pPrev = pCurr = pStop = pHead;
}

template<class T>
inline THeadList<T>::~THeadList()
{
	while (pFirst != pStop) {
		TNode<T>* newNode = pFirst;
		pFirst = pFirst->pNext;
		delete newNode;
	}
	delete pHead;
}

template<class T>
inline void THeadList<T>::InsFirst(T elem)
{
	TList::InsFirst(elem);
	pHead->pNext = pFirst;
}

template<class T>
inline void THeadList<T>::DelFirst()
{
	TList::DelFirst();
	pHead->pNext = pFirst;
}
