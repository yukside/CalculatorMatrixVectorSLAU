#include "Operations.h"
#include <iostream>

using namespace std;

Matrix transport(Matrix matrix) {
    int transRows = matrix.rows;
    int transCols = matrix.cols;

    Matrix result;
    result.init(transCols, transRows);

    for (int i = 0; i < transRows; i++) {
        for (int j = 0; j < transCols; j++) {
            double value = matrix.data[i][j];
            result.data[j][i] = value;
        }
    }
    return result;
}

double det(Matrix matrixA) {
    setlocale(LC_ALL, "Russian");
    if (matrixA.cols != matrixA.rows) {
        cout << "Ошибка: определитель считается только для квадратной матрицы!";
        return 0;
    }

    double d = 1.0;
    int pivRow;
    double fac;
    for (int i = 0; i < matrixA.rows; i++) {
        pivRow = i;

        for (int j = i + 1; j < matrixA.rows; j++) {
            if (abs(matrixA.data[j][i]) > abs(matrixA.data[pivRow][i])) {
                pivRow = j;
            }
        }

        if (pivRow != i) {
            swap(matrixA.data[pivRow], matrixA.data[i]);
            d *= -1;
        }

        for (int j = i + 1; j < matrixA.rows; j++) {
            fac = matrixA.data[j][i] / matrixA.data[i][i];

            for (int k = i; k < matrixA.cols; k++) {
                matrixA.data[j][k] -= fac * matrixA.data[i][k];
            }
        }
        d *= matrixA.data[i][i];
    }
    return d;
}

int rang(Matrix matrixA) {
    int rang = 0;
    int pivRow;
    double fac;
    for (int i = 0; i < matrixA.rows; i++) {
        pivRow = i;

        for (int j = i + 1; j < matrixA.rows; j++) {
            if (abs(matrixA.data[j][i]) > abs(matrixA.data[pivRow][i])) {
                pivRow = j;
            }
        }

        if (pivRow != i) {
            swap(matrixA.data[pivRow], matrixA.data[i]);

        }

        for (int j = rang + 1; j < matrixA.rows; j++) {
            fac = matrixA.data[j][i] / matrixA.data[rang][i];

            for (int k = i; k < matrixA.cols; k++) {
                matrixA.data[j][k] -= fac * matrixA.data[rang][k];
            }
        }
        rang++;

        if (rang == matrixA.rows) {
            break;
        }
    }

    return rang;
}

Matrix addition(Matrix matrixA, Matrix matrixB) {
    setlocale(LC_ALL, "Russian");
    int rowsR = matrixA.rows;
    int colsR = matrixA.cols;

    if (matrixA.rows != matrixB.rows || matrixA.cols != matrixB.cols) {
        cout << "Ошибка: Матрицы должны быть одинакового размера!\n";
        return Matrix();
    }

    Matrix result;
    result.init(rowsR, colsR);

    for (int i = 0; i < rowsR; i++) {
        for (int j = 0; j < colsR; j++) {
            double valueA = matrixA.data[i][j];
            double valueB = matrixB.data[i][j];
            result.data[i][j] = valueA + valueB;
        }
    }
    return result;
}

Matrix subtraction(Matrix matrixA, Matrix matrixB) {
    setlocale(LC_ALL, "Russian");
    int rowsR = matrixA.rows;
    int colsR = matrixA.cols;

    if (matrixA.rows != matrixB.rows || matrixA.cols != matrixB.cols) {
        cout << "Ошибка: Матрицы должны быть одинакового размера!\n";
        Matrix empty;
        return empty;
    }

    Matrix result;
    result.init(rowsR, colsR);

    for (int i = 0; i < rowsR; i++) {
        for (int j = 0; j < colsR; j++) {
            double valueA = matrixA.data[i][j];
            double valueB = matrixB.data[i][j];
            result.data[i][j] = valueA - valueB;
        }
    }
    return result;
}

Matrix multiplicationNum(Matrix matrixA, double k) {
    Matrix result;
    result.init(matrixA.rows, matrixA.cols);

    for (int i = 0; i < matrixA.rows; i++) {
        for (int j = 0; j < matrixA.cols; j++) {
            double valueA = matrixA.data[i][j];
            result.data[i][j] = valueA * k;
        }
    }
    return result;
}

Matrix multiplication(Matrix matrixA, Matrix matrixB) {
    setlocale(LC_ALL, "Russian");
    if (matrixA.cols != matrixB.rows) {
        cout << "Ошибка: Количество столбцов первой матрицы должно совпадать с количеством строк второй матрицы!\n";
        Matrix empt;
        return empt;
    }

    int rowsR = matrixA.rows;
    int colsR = matrixB.cols;
    Matrix result;
    result.init(rowsR, colsR);

    Matrix transportB;
    int transRows = matrixB.rows;
    int transCols = matrixB.cols;
    transportB.init(transCols, transRows);

    for (int i = 0; i < transRows; i++) {
        for (int j = 0; j < transCols; j++) {
            double value = matrixB.data[i][j];
            transportB.data[j][i] = value;
        }
    }

    for (int i = 0; i < matrixA.rows; i++) {
        for (int j = 0; j < matrixB.cols; j++) {
            double sm = 0;
            for (int k = 0; k < matrixA.cols; k++) {
                sm += matrixA.data[i][k] * transportB.data[j][k];
                result.data[i][j] = sm;
            }
        }
    }
    return result;
}




//SLAU
Matrix metMat(Matrix matrixA) { return matrixA; }
Matrix metGr(Matrix matrixA) { return matrixA; }
Matrix metKram(Matrix matrixA) { return matrixA; }


//Vectors
Vector additionV(Vector vectorA, Vector vectorB) {
    if (vectorA.size != vectorB.size) {
        cout << "Векторы должны быть одинакового размера!";
        Vector empty;
        return empty;
    }

    Vector resVec;
    resVec.init(vectorA.size);

    for (int i = 0; i < resVec.size; i++) {
        resVec.data[i] = vectorA.data[i] + vectorB.data[i];
    }

    return resVec;
}

Vector subtractionV(Vector vectorA, Vector vectorB) {
    if (vectorA.size != vectorB.size) {
        cout << "Векторы должны быть одинакового размера!";
        Vector empty;
        return empty;
    }

    Vector resVec;
    resVec.init(vectorA.size);

    for (int i = 0; i < resVec.size; i++) {
        resVec.data[i] = vectorA.data[i] - vectorB.data[i];
    }

    return resVec;
}

Vector multiplactionNumV(Vector vectorA, double k) {
    Vector resVec;
    resVec.init(vectorA.size);

    for (int i = 0; i < resVec.size; i++) {
        resVec.data[i] = vectorA.data[i] * k;
    }

    return resVec;
}

double scalarV(Vector vectorA, Vector vectorB) {
    if (vectorA.size != vectorB.size) {
        cout << "Векторы должны быть одинакового размера!";
        return 0;
    }

    double res = 0;

    for (int i = 0; i < vectorA.size; i++) {
        res += vectorA.data[i] * vectorB.data[i];
    }

    return res;
}

Vector vecV(Vector vectorA, Vector vectorB) {
    if (vectorA.size != vectorB.size) {
        cout << "Размерности должны быть одинаковыми!\n";
        Vector empty;
        return empty;
    }

    if (vectorA.size != 3) {
        cout << "Только трехмерное пространнство";
        Vector empty;
        return empty;
    }

    Vector resVec;
    resVec.init(vectorA.size);

    resVec.data[0] = vectorA.data[1] * vectorB.data[2] - vectorA.data[2] * vectorB.data[1];
    resVec.data[1] = vectorA.data[2] * vectorB.data[0] - vectorA.data[0] * vectorB.data[2];
    resVec.data[2] = vectorA.data[0] * vectorB.data[1] - vectorA.data[1] * vectorB.data[0];

    return resVec;
}

double smeshV(Vector vectorA, Vector vectorB, Vector vectorC) {
    return 0;
}