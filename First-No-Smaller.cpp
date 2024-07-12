#include <iostream>
#include <string>
#include <vector>

using namespace std;

int first_not_smaller(const std::vector<int>& arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    int l = 0;
    int r = arr.size() - 1;
    int boundary_index = 0;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= target) {
            boundary_index = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return boundary_index;
}


int main() {

    const vector<int>v {1, 3, 3, 3, 3, 3, 3};
    const int target = 3;

    cout << first_not_smaller(v, target);
}