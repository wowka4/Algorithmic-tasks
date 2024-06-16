#include <vector>

int search(vector<int>& nums, int target) {

    int start = 0;
    int finish = nums.size() - 1;
    bool isFound = false;
    int mid;
    sort(nums.begin(), nums.end());

    while((start <= finish) && (isFound != true)) {
        mid = (start + finish) / 2;
        if (nums[mid] == target) isFound = true;
        if (nums[mid] > target) finish = mid - 1;
        else start = mid + 1;
    }
    if (isFound == false) return -1;

    return mid;

}