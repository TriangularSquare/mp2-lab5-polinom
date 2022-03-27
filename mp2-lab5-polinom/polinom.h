#pragma once
#include "headlist.h"
#include<sstream>
using namespace std;

struct TMonom {
	double coeff;
	int x, y, z;

	TMonom(int _x = 0, int _y = 0, int _z = 0, double _coeff = 0) {
		coeff = _coeff;
		x = _x;
		y = _y;
		z = _z;
	}

	TMonom operator*(const TMonom& other) {
		TMonom res;
		res.coeff = coeff * other.coeff;
		res.x = x + other.x;
		res.y = y + other.y;
		res.z = z + other.z;
		return res;
	}

	bool IsConst() const {
		return x == 0 && y == 0 && z == 0;
	}

	bool operator==(const TMonom& tm) {
		return (x == tm.x) && (y == tm.y) && (z == tm.z);
	}

	bool operator<(const TMonom& tm) {
		return (100 * x + 10 * y + z) < (100 * tm.x + 10 * tm.y + tm.z);
	}

	bool operator>(const TMonom& tm) {
		return (100 * x + 10 * y + z) > (100 * tm.x + 10 * tm.y + tm.z);
	}

	friend std::ostream& operator<<(std::ostream& os, TMonom& monom)
	{
		if (monom.x != 0)
		{
			os << "x";
			if (monom.x != 1)
				os << monom.x;
		}
		if (monom.y != 0)
		{
			os << "y";
			if (monom.y != 1)
				os << monom.y;
		}
		if (monom.z != 0)
		{
			os << "z";
			if (monom.z != 1)
				os << monom.z;
		}
		return os;
	}
};


class TPolinom : public THeadList<TMonom> {
protected:
	void Print(std::ostream& os) const;
public:
	TPolinom();
	TPolinom(TPolinom& tp);

	TPolinom& operator=(TPolinom& tp);

	void AddMonom(TMonom m);

	bool operator==(TPolinom& other);
	bool operator!=(TPolinom& other);

	TPolinom operator+(TPolinom& other);
	TPolinom operator-(TPolinom& other);
	TPolinom operator*(TPolinom& other);
	TPolinom operator*(TMonom& monom);
	TPolinom operator*(double a);

	friend TPolinom operator*(
		TMonom& m,
		TPolinom& p)
	{
		return p * m;
	}

	friend TPolinom operator*(
		double a,
		TPolinom& p)
	{
		return p * a;
	}

	friend std::ostream& operator<<(
		std::ostream& os,
		TPolinom& p)
	{
		p.Print(os);
		return os;
	}
};

inline void TPolinom::Print(std::ostream& os) const
{
	TNode<TMonom>* _pCurr = pFirst;

	if (_pCurr == pStop)
	{
		os << "0";
		return;
	}

	TMonom m = _pCurr->val;
	double absCoeff = fabs(m.coeff);

	if (m.coeff < 0) os << "- ";

	if (m.IsConst())
	{
		os << absCoeff;
	}

	else
	{
		if (absCoeff != 1) os << absCoeff << "*";
		os << m;
	}

	_pCurr = _pCurr->pNext;

	for (; _pCurr != pStop; _pCurr = _pCurr->pNext)
	{
		TMonom m = _pCurr->val;
		double absCoeff = fabs(m.coeff);

		if (m.coeff < 0) os << " - ";
		else os << " + ";

		if (m.IsConst())
		{
			os << absCoeff;
		}
		else
		{
			if (absCoeff != 1)
				os << absCoeff << "*";
			os << m;
		}
	}
}

inline TPolinom::TPolinom()
{
	TMonom m(0, 0, -1);
	pHead->val = m;
}

inline TPolinom::TPolinom(TPolinom& tp)
{
	TMonom m(0, 0, -1);
	pHead->val = m;
	for (tp.Reset(); !tp.IsEnd(); tp.GoNext()) {
		InsLast(tp.GetCurr());
	}
}

inline TPolinom& TPolinom::operator=(TPolinom& tp)
{
	while (pFirst != pStop)
	{
		DelFirst();
	}

	pFirst = pLast = pPrev = pCurr = pStop = pHead;
	len = 0;

	tp.Reset();
	while (!tp.IsEnd())
	{
		InsLast(tp.GetCurr());
		tp.GoNext();
	}
	return *this;
}

inline void TPolinom::AddMonom(TMonom m)
{
	Reset();

	while (m < pCurr->val)
	{
		GoNext();
	}

	if (pCurr->val == m)
	{
		pCurr->val.coeff += m.coeff;
		if (pCurr->val.coeff == 0)
		{
			DelCurrent();
		}
	}
	else
	{
		InsCurrent(m);
	}
}

inline bool TPolinom::operator==(TPolinom& other)
{
	TPolinom oth(other);
	Reset();
	oth.Reset();

	while (!IsEnd()) {
		if (!(pCurr->val == oth.pCurr->val)) {
			return false;
		}
		else {
			GoNext();
			oth.GoNext();
		}
	}

	return true;
}

inline bool TPolinom::operator!=(TPolinom& other)
{
	return !(this == &other);
}

inline TPolinom TPolinom::operator+(TPolinom& other)
{
	TPolinom res(other);
	Reset();
	res.Reset();

	while (!IsEnd())
	{
		if (res.pCurr->val > pCurr->val)
		{
			res.GoNext();
		}
		else if (res.pCurr->val < pCurr->val)
		{
			res.InsCurrent(pCurr->val);
			GoNext();
		}
		else
		{
			res.pCurr->val.coeff += pCurr->val.coeff;
			if (res.pCurr->val.coeff == 0)
			{
				res.DelCurrent();
				GoNext();
			}
			else
			{
				res.GoNext();
				GoNext();
			}
		}
	}
	return res;
}

inline TPolinom TPolinom::operator-(TPolinom& other)
{
	return operator+(other.operator*(-1));
}

inline TPolinom TPolinom::operator*(TPolinom& other)
{
	TPolinom res;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		TPolinom temp = m * other;
		res = res + temp;
	}

	return res;
}

inline TPolinom TPolinom::operator*(TMonom& monom)
{
	TPolinom res;

	if (monom.coeff == 0) return res;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		res.InsLast(m * monom);
	}

	return res;
}

inline TPolinom TPolinom::operator*(double a)
{
	TPolinom res;

	if (a == 0) return res;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		m.coeff *= a;

		res.InsLast(m);
	}
	return res;
}
