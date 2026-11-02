#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() {
	rows = 0;
	cols = 0;
}

void Matrix::init(int r, int c) {
	rows = r;
	cols = c;
	data.resize(rows, vector<double>(cols, 0));
}

void Matrix::input() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> data[i][j];
		}
	}
}

void Matrix::print() {
	setlocale(LC_ALL, "Russian");
	cout << "Матрицы:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << data[i][j] << " ";
		}
		cout << "\n";
	}
}

