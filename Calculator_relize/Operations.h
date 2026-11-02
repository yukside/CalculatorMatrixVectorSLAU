#pragma once
#include "Matrix.h"
#include "Vector.h"
using namespace std;

Matrix transport(Matrix matrix);
double det(Matrix matrixA);
int rang(Matrix matrixA);

Matrix addition(Matrix matrixA, Matrix matrixB);
Matrix subtraction(Matrix matrixA, Matrix matrixB);
Matrix multiplication(Matrix matrixA, Matrix matrixB);
Matrix multiplicationNum(Matrix matrixA, double k);

//SLAU
Matrix metMat(Matrix matrixA);
Matrix metGr(Matrix matrixA);
Matrix metKram(Matrix matrixA);

Vector additionV(Vector vectorA, Vector vectorB);
Vector subtractionV(Vector vectorAA, Vector vectorB);
Vector multiplactionNumV(Vector vectorA, double k);
double scalarV(Vector vectorA, Vector vectorB);
Vector vecV(Vector vectorA, Vector vectorB);
double smeshV(Vector vectorA, Vector vectorB, Vector vectorC);



