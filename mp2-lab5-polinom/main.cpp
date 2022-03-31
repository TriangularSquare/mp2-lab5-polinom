#include <iostream>
using namespace std;
#include "polinom.h"
#include <locale.h>



void main() {
	setlocale(LC_ALL, "Russian");
	TPolinom tp1, tp2;
	int n;
	cout << "Число мономов в первом полиноме: ";
	cin >> n;
	cout << "\n Введите параметры мономов \n";
	for (int i = 0; i < n; i++) {
		double coeff;
		int x, y, z;
		cin >> coeff >> x >> y >> z;
		TMonom tm(coeff, x, y, z);
		tp1.AddMonom(tm);
	}

	cout << "Число мономов во второмом полиноме: ";
	cin >> n;
	cout << "\n Введите параметры мономов \n";
	for (int i = 0; i < n; i++) {
		double coeff;
		int x, y, z;
		cin >> coeff >> x >> y >> z;
		TMonom tm(coeff, x, y, z);
		tp2.AddMonom(tm);
	}

	cout << tp1 << '\n';
	cout << tp2 << '\n';
	cout << "Сумма:" << tp1 + tp2 << '\n';
	cout << "Разность:" << tp1 - tp2 << '\n';
	cout << "Произведение:" << tp1 * tp2 << '\n';
	cout << "Умножение полинома на 2:" << tp1 * 2 << '\n';
	TMonom tm(3, 3, 4, 7);
	cout << "Умножение полинома на моном:" << tp1 * tm << '\n';
}
