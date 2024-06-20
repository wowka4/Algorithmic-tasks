#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> a;
    int i = 0;
    while (i < nums.size()) {
        int res = target - nums[i];
        if (a.find(res) == a.end()) {
            a[nums[i]] = i;
        } else {
            return {a[res], i};
        }
        i++;
    }
}

int main() {

    vector<int>v {3,3};
    int target = 6;
    vector<int> p;
    p = twoSum(v, target);

    for (int g : p) {
        cout << g << " ";
    }
}