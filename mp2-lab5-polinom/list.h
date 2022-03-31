#pragma once

template <class T>
struct TNode {
	T val;
	TNode* pNext;
};


template <class T>
class TList {
protected:
	TNode<T>* pFirst, * pCurr, * pPrev, * pLast, * pStop;
	int len;
public:
	TList();
	virtual ~TList();

	bool IsEmpty();

	virtual void InsFirst(T value);
	void InsLast(T value);
	void InsCurrent(T value);

	virtual void DelFirst();
	void DelCurrent();

	void Reset();
	void GoNext();
	bool IsEnd();
	T GetCurr();
};

template<class T>
inline TList<T>::TList()
{
	len = 0;
	pStop = nullptr;
	pFirst = pCurr = pPrev = pLast = pStop;
}

template<class T>
inline TList<T>::~TList()
{
	while (pFirst != pStop) {
		TNode<T>* newNode = pFirst;
		pFirst = pFirst->pNext;
		delete newNode;
	}
}

template<class T>
inline bool TList<T>::IsEmpty()
{
	return pFirst == pStop;
}

template<class T>
inline void TList<T>::InsFirst(T value)
{
	TNode<T>* newNode = new TNode<T>;
	newNode->val = value;
	newNode->pNext = pFirst;
	pFirst = newNode;

	len++;

	if (len == 1) {
		pLast = pFirst;
	}
}

template<class T>
inline void TList<T>::InsLast(T value)
{
	if (len > 0) {
		TNode<T>* newNode = new TNode<T>;
		newNode->val = value;
		newNode->pNext = pStop;
		pLast->pNext = newNode;
		pLast = newNode;

		len++;
	}
	else {
		InsFirst(value);
	}
}

template<class T>
inline void TList<T>::InsCurrent(T value)
{
	if (pCurr == pFirst) {
		InsFirst(value);
		pPrev = pFirst;
	}
	else if (pCurr == pLast) {
		InsLast(value);
		pPrev = pLast;
	}
	else {
		TNode<T>* newNode = new TNode<T>;
		newNode->val = value;
		newNode->pNext = pCurr;
		pPrev->pNext = newNode;
		pCurr = newNode;
		len++;
	}
}

template<class T>
inline void TList<T>::DelFirst()
{
	if (IsEmpty()) {
		throw "List is empty";
	}

	if (pCurr == pFirst) {
		pPrev = pStop;
		pCurr = pCurr->pNext;
	}

	TNode<T>* newNode = pFirst;
	pFirst = newNode->pNext;
	delete newNode;

	len--;

	/*
	if (pFirst == pStop) {
		pLast = pStop;
	}*/
}

template<class T>
inline void TList<T>::DelCurrent()
{
	if (pCurr == pStop) {
		throw "List is empty";
	}

	if (pCurr == pFirst) {
		DelFirst();
		pPrev = pStop; 
		pCurr = pFirst;
	}
	else {
		TNode<T>* newNode = pCurr;
		pCurr = pCurr->pNext;
		pPrev->pNext = pCurr;
		delete newNode;

		len--;
	}
}

template<class T>
inline void TList<T>::Reset()
{
	pPrev = pStop;
	pCurr = pFirst;
}

template<class T>
inline void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template<class T>
inline bool TList<T>::IsEnd()
{
	return (pCurr == pStop);
}

template<class T>
inline T TList<T>::GetCurr()
{
	if (pCurr == pStop)
		throw "Can't get current element: it's a barrier";
	return pCurr->val;
}
