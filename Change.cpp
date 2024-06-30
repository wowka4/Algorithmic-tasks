#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
std::vector<int> Change(const std::vector<int>& nums, const int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    vector<int>res;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        while(result <= target) {
            result += nums[i];
            if (result <= target) res.push_back(nums[i]);
        }
        if (result != target)result -= nums[i];
    }
    return res;
}


int main() {

    vector<int>v {25,10,5,1};
    int target {189};

    const vector<int>v1 = Change(v, target);

    for (const int i : v1) {
        cout << i << " ";
    }

}