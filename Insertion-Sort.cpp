#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v {54, 63, -12, 3, -98,17, 65, 6, 1};

    for (int a : v) {
        cout << a << " ";
    }
    cout << "=========================" << endl;
    cout << "After sorting" << endl;

    for (int i = 0; i < v.size(); i++) {
        int current = i;

        while (current > 0 && v[current] < v[current - 1]) {
            int temp = v[current];
            v[current] = v[current - 1];
            v[current - 1] = temp;
            current--;
        }
    }

    for (int a : v) {
        cout << a << " ";
    }

}