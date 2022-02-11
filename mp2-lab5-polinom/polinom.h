#pragma once

struct TMonom {
	double coeff;
	int x, y, z;
	bool operator==(const TMonom& tm) {
		return (x == tm.x) && (y == tm.y) && (z == tm.z);
	}
	bool operator<(const TMonom& tm) {
		return (100 * x + 10 * y + z) < (100 * tm.x + 10 * tm.y + tm.z);
	}
};

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
	~TList();
	
	bool IsEmpty();

	void InsFirst(T value);
	void InsLast(T value);
	void InsCurrent(T value);

	void delFirst();
	void delCurrent();
};

template<class T>
inline TList<T>::TList()
{
	len = 0;
	pStop = nullptr;
	pFirst = pCurr = pPrev = pLast = pStop;
}

template<class T>
inline bool TList<T>::IsEmpty()
{
	return len == 0;
}

template<class T>
inline void TList<T>::InsFirst(T value)
{
	TNode<T> newNode = new TNode<T>;
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
		TNode<T> newNode = new TNode<T>;
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
	}
	else if (pCurr == pLast) {
		InsLast(value);
	}
	else {
		TNode<T> newNode = new TNode<T>;
		newNode->val = value;
		newNode->pNext = pCurr;
		pCurr = newNode;
		pPrev->pNext = pCurr;
		len++;
	}
}

template<class T>
inline void TList<T>::delFirst()
{
	if (IsEmpty()) {
		throw "List is empty";
	}

	TNode<T> newNode = pFirst;
	pFirst = newNode->pNext;
	delete newNode;

	len--;

	if (pFirst == pStop) {
		pLast = pStop;
	}
}

template<class T>
inline void TList<T>::delCurrent()
{
	if (IsEmpty()) {
		throw "List is empty";
	}

	if (pCurr == pFirst) {
		delFirst();
	}
	else {
		TNode<T> newNode = pCurr;
		pCurr = newNode->pNext;
		pPrev->pNext = pCurr;
		delete newNode;

		len--;
	}
}
