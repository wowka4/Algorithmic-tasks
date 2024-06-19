#include <iostream>
#include <vector>

using namespace std;

float find_uniq(const std::vector<float> v) {

    float num1 = v[0];
    float num2 = v[1];

    for (int i = 2; i < v.size(); i++) {

        if (num1 == num2) {
            if (v[i] != num2) {
                return v[i];
            }
        } else {
            if (v[i] == num1) return num2;
            return num1;
        }
    }
}

int main() {


    vector<float>v { 1,1,1,1,1,1,1,1,1,1,1,1,1,14,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


}
