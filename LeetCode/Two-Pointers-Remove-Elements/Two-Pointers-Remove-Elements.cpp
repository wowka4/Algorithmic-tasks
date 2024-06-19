#include <iostream>
#include <vector>

using namespace std;


int removeElement(vector<int>& nums, int val) {

    int counter = 0;
    int reader = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            int additional = nums[reader];
            nums[reader++] = nums[i];
            nums[i] = additional;
            counter++;
        }
    }
    return counter;
}

int main() {

    vector<int>v {0,1,2,2,3,0,4,2};
    int val {2};

    cout << removeElement(v, val);

}
