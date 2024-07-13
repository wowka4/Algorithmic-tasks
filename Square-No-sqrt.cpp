#include <iostream>
#include <vector>

using namespace std;


int square_root(int n) {
    vector<int>v;

    for (int i = 0; i <= n ; ++i) {
        v.push_back(i);
    }

    int l = 0;
    int r = v.size() - 1;
    int res = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid] * v[mid] == n) return mid;
        if (v[mid] * v[mid] <= n) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}


int main() {

    cout << square_root(1);

}