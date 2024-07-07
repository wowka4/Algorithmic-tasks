#include <iostream>
#include <vector>

using namespace std;
int subarray_sum_fixed(std::vector<int> nums, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    int max_num = 0;
    for (int i = k; i < nums.size(); ++i) {
        int res = nums[i - 1] + nums[i - 2] + nums[i - 3];
        max_num = max(max_num, res);
    }
    return max_num;
}

int main() {

    vector<int>v { 1, 2, 3, 7, 4, 1 };
    int k = 3;
    cout << subarray_sum_fixed(v, k);

}