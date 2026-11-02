#pragma once
#include <vector>
#include <iostream> 
using namespace std;

class Matrix {
public:
	int rows;
	int cols;
	vector<vector<double>> data;

	Matrix();

	void init(int r, int c);
	void input();
	void print();

};