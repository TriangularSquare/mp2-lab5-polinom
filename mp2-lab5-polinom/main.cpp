#include <iostream>
using namespace std;
#include "polinom.h"

void main() {
	TList<int> list;
	int num, size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> num;
		list.InsCurrent(num);
	}
	//cout << list.GetCurr();
	for (list.Reset(); !list.IsEnd(); list.GoNext()) {
		cout << list.GetCurr() << " ";
	}
}