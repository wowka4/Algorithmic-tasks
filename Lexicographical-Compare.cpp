#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // считайте входные данные и сформируйте вывод программы
    // ...
    int num;
    cin >> num;
    vector<string>v;

    for (int i = 0; i < num; ++i) {
        string word;
        cin >> word;
        v.push_back(word);
    }
    sort(v.begin(), v.end(),
        [](const string& s1, const string& s2) {
            return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
                [] (const char c1, const char c2) {
                    return tolower(c1) < tolower(c2);
                });
        });

    for (const string& a : v) {
        cout << a << " ";
    }
}
