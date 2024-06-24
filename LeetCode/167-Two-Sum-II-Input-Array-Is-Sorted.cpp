#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int a = 0;
    int b = numbers.size() - 1;

    while(a < b) {
        if (numbers[a] + numbers[b] < target) {
            a++;
        } else if (numbers[a] + numbers[b] > target) {
            b--;
        } else {
            return {a+=1, b+=1};
        }

    }
    return {};
}