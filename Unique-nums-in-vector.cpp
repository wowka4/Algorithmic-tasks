/*Дано N чисел, требуется выяснить, сколько среди них различных.

Входные данные
В первой строке дано число N – количество чисел. (1 <= N <= 100000) Во второй строке даны через пробел N чисел, каждое не превышает 2*109 по модулю.

Выходные данные
Выведите число, равное количеству различных чисел среди данных.

Sample Input:
5
1 0 1 2 0
Sample Output:
3
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    // put your code here
    int k;
    cin >> k;
    vector<int>v;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    set<int>st(v.begin(), v.end());

    cout << st.size();
    return 0;
}