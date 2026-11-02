#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Vector
{
public:
	int size;
	vector<double> data;

	Vector();

	void init(int r);
	void input();
	void print();
};

