#include <iostream>
#include <vector>

using namespace std;


int C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return C(n - 1, k - 1) * n / k;
}


int main() {
    int n, k;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите k: ";
    cin >> k;
    cout << "Число сочетаний (С из n по k): " << C(n, k) << endl;
}

