#include "Vector.h"
using namespace std;


Vector::Vector() {
	size = 0;
}

void Vector::init(int r) {
	size = r;
	data.resize(size);
}

void Vector::input() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите координаты вектора: \n";

	for (int i = 0; i < size; i++) {
		cin >> data[i];
	}
}

void Vector::print() {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << "\n";
}

