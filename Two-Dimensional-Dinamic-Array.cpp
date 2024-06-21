#include <iostream>

using namespace std;

int rows;
int cols;
cout << "Enter rows number" << " ";
cin >> rows;
cout << "Enter columns number" << " ";
cin >> cols;

int **arr = new int* [rows]; // Создал массив массивов

for (int i = 0; i < rows; ++i) { // Создаю подмассивы
    arr[i] = new int[cols];
}

//////////////////////////////////

for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) { // Заполняю массивы
        arr[i][j] = rand() % 50;
    }
}

////////////////////////////////////////

for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) { // Вывожу массивы в консоль
        cout << arr[i][j] << "\t";
    }
    cout << endl;
}

///////////////////////////////////

for (int i = 0; i < rows; ++i) { // удаляю подмассивы из памяти
    delete [] arr[i];
}

delete [] arr;