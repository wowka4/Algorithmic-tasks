#include <iostream>
#include <vector>

using namespace std;
int main() {

    //Bubble Sort

    vector<int>v{45,54,34,32,1,43,3,-54,-76,600,-999};
    for (int a : v) {
        cout << a << " ";
    }
    cout << endl;
    cout << "=====================================" << endl;
    int n = v.size() - 1;
    for (int i = n; i >= 0; i--) {
        bool swapped = false;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    for (int a : v) {
        cout << a << " ";
    }
}
