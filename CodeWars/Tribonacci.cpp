#include <iostream>
#include <vector>

using namespace std;

std::vector<int> tribonacci( std::vector<int> signature, int n)
{
    std::vector<int> result;
    if (n < 3) {
        for (int i = 0; i < n; ++i) {
            result.push_back(signature[i]);
        }
        return result;
    }

    int window = 0;
    int len = signature.size();

    for (int i = 0; i < len; ++i) {
        window += signature[i];
        result.push_back(signature[i]);
    }
    result.push_back(window);
    int l = 0;
    for (int i = len; i < n - 1; ++i) {
        window = window - result[l++] + result[i];
        result.push_back(window);
    }

    return result;
}

int main() {


    vector<int>v = tribonacci({ 1, 2, 3}, 2);

    for (int a : v) {
        cout << a << " ";
    }
}