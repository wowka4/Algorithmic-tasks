#include <iostream>
#include <vector>

using namespace std;



int removeDuplicates(vector<int>& nums) {

    int k = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    vector<int>v {0,0,1,1,1,2,2,3,4,4};

    removeDuplicates(v);

    for (int a : v) {
        cout << a << " ";
    }

}
