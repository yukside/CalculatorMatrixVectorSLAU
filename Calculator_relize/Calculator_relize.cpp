#include <iostream>
#include <string>
#include "Matrix.h"
#include "Operations.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Matrix matrixA;
    Matrix matrixB;
    Matrix resMat;

    int rowsA;
    int colsA;
    int rowsB;
    int colsB;

    Vector vectorA;
    Vector vectorB;
    Vector vectorC;
    Vector resVec;
    
    int rA;
    int rB;
    int rC;

    double k;
    int choiceMenu;
    int choice = -1;

    cout << "---Меню---\n";
    cout << "1. Матричный калькулятор\n";
    cout << "2. Векторный калькулятор\n";
    cout << "3. Решение СЛАУ\n";
    cout << "0. Выход\n";
    cout << "Выберите число: ";
    cin >> choiceMenu;

    switch (choiceMenu) {
        case 1: 
            cout << "\n====Матричный Калькулятор====\n";
            cout << "Введите размеры матрицы А черех пробел\n";
            cin >> rowsA >> colsA;
            matrixA.init(rowsA, colsA);
            matrixA.input();

            cout << "Введите размеры матрицы В через пробел\n";
            cin >> rowsB >> colsB;
            matrixB.init(rowsB, colsB);
            matrixB.input();

            while (choice != 0) {
                cout << "=====ОПЕРАЦИИ=====\n";
                cout << "1. Транспонирование\n";
                cout << "2. Определитель\n";
                cout << "3. Ранг\n";
                cout << "4. Сложение\n";
                cout << "5. Разность\n";
                cout << "6. Умножение на число\n";
                cout << "7. Умножение\n";
                cout << "0. Выход\n";
                cout << "Выбор: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    resMat = transport(matrixA);
                    resMat.print();
                    break;
                case 2:
                    cout << det(matrixA) << "\n";
                    break;
                case 3:
                    cout << rang(matrixA) << "\n";
                    break;
                case 4:
                    resMat = addition(matrixA, matrixB);
                    resMat.print();
                    break;
                case 5:
                    resMat = subtraction(matrixA, matrixB);
                    resMat.print();
                    break;
                case 6:
                    cout << "Введите число: ";
                    cin >> k;
                    resMat = multiplicationNum(matrixA, k);
                    resMat.print();
                    break;
                case 7:
                    resMat = multiplication(matrixA, matrixB);
                    resMat.print();
                    break;
                }
            }
            break;

        case 2:
            cout << "\n====Векторный Калькулятор====\n";
            cout << "Введите размер вектора А\n";
            cin >> rA;
            vectorA.init(rA);
            vectorA.input();

            cout << "Введите размер вектора B\n";
            cin >> rB;
            vectorB.init(rB);
            vectorB.input();

            cout << "Введите размер вектора C\n";
            cin >> rC;
            vectorC.init(rC);
            vectorC.input();

            while (choice != 0) {
                cout << "=====ОПЕРАЦИИ=====\n";
                cout << "1. Сложение\n";
                cout << "2. Разность\n";
                cout << "3. Произведение на число\n";
                cout << "4. Скалярное произведение\n";
                cout << "5. Векторное произведение\n";
                cout << "6. Смешанное произведение\n";
                cout << "0. Выход\n";
                cout << "Выбор: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    resVec = additionV(vectorA, vectorB);
                    resVec.print();
                    break;
                case 2:
                    resVec = subtractionV(vectorA, vectorB);
                    resVec.print();
                    break;
                case 3:
                    cout << "Введите число: ";
                    cin >> k;
                    resVec = multiplactionNumV(vectorA, k);
                    resVec.print();
                    break;
                case 4:
                    cout << scalarV(vectorA, vectorB) << "\n";
                    break;
                case 5:
                    resVec = vecV(vectorA, vectorB);
                    resVec.print();
                    break;
                case 6:
                    resVec = vecV(vectorB, vectorC);
                    cout << scalarV(vectorA, resVec) << "\n";
                    break;
                }
            }
            break;
        case 3:
            cout << "\n====Векторный Калькулятор====\n";
            cout << "Введите размер вектора А\n";
            cin >> rA;
            vectorA.init(rA);
            vectorA.input();

            cout << "Введите размер вектора B\n";
            cin >> rB;
            vectorB.init(rB);
            vectorB.input();

            cout << "Введите размер вектора C\n";
            cin >> rC;
            vectorC.init(rC);
            vectorC.input();

            while (choice != 0) {
                cout << "=====ОПЕРАЦИИ=====\n";
                cout << "1. Сложение\n";
                cout << "2. Разность\n";
                cout << "3. Произведение на число\n";
                cout << "4. Скалярное произведение\n";
                cout << "5. Векторное произведение\n";
                cout << "6. Смешанное произведение\n";
                cout << "0. Выход\n";
                cout << "Выбор: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    resVec = additionV(vectorA, vectorB);
                    resVec.print();
                    break;
                case 2:
                    resVec = subtractionV(vectorA, vectorB);
                    resVec.print();
                    break;
                case 3:
                    cout << "Введите число: ";
                    cin >> k;
                    resVec = multiplactionNumV(vectorA, k);
                    resVec.print();
                    break;
                case 4:
                    cout << scalarV(vectorA, vectorB) << "\n";
                    break;
                case 5:
                    resVec = vecV(vectorA, vectorB);
                    resVec.print();
                    break;
                case 6:
                    resVec = vecV(vectorB, vectorC);
                    cout << scalarV(vectorA, resVec) << "\n";
                    break;
                }
            }
            break;
        case 0:
            break;
    }

    return 0;


}
