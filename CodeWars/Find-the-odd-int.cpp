#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


int findOdd(const vector<int>& numbers){
    int count = 1;

    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] == numbers[i - 1]) count++;
        if (numbers[i] != numbers[i - 1])
            if (count % 2 != 0) return numbers[i - 1];
            else count = 1;
    }
    if (count == 1) return numbers[numbers.size() - 1];
}

int main() {


    vector<int>v { 1,2,2,3,3,3,4,3,3,3,2,2,1 };
    sort(v.begin(), v.end());

    cout << findOdd(v);


}

