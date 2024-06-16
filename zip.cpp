#include <iostream>

using namespace std;


int main() {
    int size;
    cin >> size;
    int a[size];
    int b[size];
    int index = 0;
    while (index != size) {
        cin >> a[index];
        index++;
    }
    index = 0;
    while (index != size) {
        cin >> b[index];
        index++;
    }

    int c[size * 2];
    index = 0;
    int len = size * 2;
    for (int i = 0; i < len; i += 2) {
        c[i] = a[index];
        index++;
    }
    index = 0;
    for (int i = 1; i < len; i+= 2) {
        c[i] = b[index];
        index++;
    }

    for(int d : c) {
        cout << d << " ";
    }
}