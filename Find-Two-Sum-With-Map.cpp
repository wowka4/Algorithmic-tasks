#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <regex>

using namespace std;





int main() {

    int size, key;
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        array[i] = value;
    }

    set<int>mp;

    cin >> key;
    bool isFound = false;
    sort(array, array + size);
    int second;
    for (int i = 0; i < size; i++) {
        second = key - array[i];
        auto result = mp.find(second);
        if ( result == mp.end()) {
            mp.insert(array[i]);
        } else {
            isFound = true;
            cout << second << " " << array[i];
            break;
        }
    }
    if (isFound == false) cout << "None";
}
