#include <iostream>
#include <vector>

using namespace std;
int main() {

    //Selection Sort

    vector<int>v{45,54,34,32,1,43,3,-54,-76,600,-999};

    for (int i = 0; i < v.size(); i++) {
        int min = i;
        for (int j = i; j < v.size(); j++) {
            if (v[min] > v[j]) {
                min = j;
            }
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }

    for (int a : v) {
        cout << a << " ";
    }

}
