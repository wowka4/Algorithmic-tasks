#include <iostream>

using namespace std;

bool judgeSquareSum(int c) {
    if (c == 1) return true;
    long a = 0;
    long b = static_cast<long>(sqrt(c));

    while(a <= b) {
        long result = (a * a) + (b * b);
        if ( result == c) return true;
        if (result > c) {
            b -= 1;
        }
        if (result < c) {
            a += 1;
        }
    }
    return false;
}


int main() {

    int a = 100000;
    cout << judgeSquareSum(a);


}