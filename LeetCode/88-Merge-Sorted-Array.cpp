#include <iostream>
#include <vector>


using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = n + m - 1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}


int main() {

    vector<int>v {1, 2, 3, 0, 0, 0};
    vector<int>v1 {2, 5, 6};
    int a = 3, b = 3;

    merge(v,a,v1,b);

    for (int i : v) {
        cout << i << " ";
    }



}
