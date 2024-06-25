#include <iostream>

using namespace std;



void FillArray(int* &arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 15;
    }
}

void ShowArray(const int* const &arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << "\t";
    }
    cout << endl;
}

void Push_Back(int* &arr, int &size, int value) {

    int *newArray = new int[size + 1];

    for (int i = 0; i < size; ++i) {
        newArray[i] = arr[i];
    }
    newArray[size] = value;
    size++;

    delete [] arr;
    arr = newArray;
}

void Pop_Back(int* &arr, int &size) {
    int *newArray = new int[size - 1];

    for (int i = 0; i < size - 1; ++i) {
        newArray[i] = arr[i];
    }

    size--;
    delete []arr;

    arr = newArray;
}

void Push_Middle(int* &arr, int &size, int value) {

    int* newArray = new int[size + 1];
    size++;

    for (int i = 0; i < size / 2; ++i) {
        newArray[i] = arr[i];
    }

    newArray[size / 2] = value;

    for (int i = size / 2 + 1; i < size; ++i) {
        newArray[i] = arr[i - 1];
    }

    delete []arr;
    arr = newArray;
}

int main() {

    int size = 10;
    int *arr = new int [size];

    FillArray(arr,size);

    ShowArray(arr, size);

    Push_Back(arr, size, 88);

    ShowArray(arr, size);

    Pop_Back(arr, size);

    ShowArray(arr, size);

    Push_Middle(arr, size, 19);

    ShowArray(arr, size);

    cout << size;


    delete [] arr;


}
