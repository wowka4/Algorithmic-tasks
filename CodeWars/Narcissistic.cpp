#include <iostream>
#include <cmath>

using namespace std;

bool narcissistic( int value )
{
    int count = to_string(value).size();

    int sum = 0;

    int number = value;

    while (number != 0) {
        int num = number % 10;
        sum += pow(num, count);
        number /= 10;
    }

    return sum == value;

}

int main() {

    int number = 153;
    cout << narcissistic(number);

}