#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    int occurs = 0;

    for (int i = 0; i < haystack.size(); ++i) {
        if (haystack[i] == needle[occurs]) {
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
    }
    return -1;
}

int main() {


    string haystack = "sadbutsad", needle = "sad";
    string haystack1 = "leetcode", needle1 = "leeto";
    string haystack2 = "hello", needle2 = "ll";
    string haystack3 = "mississippi", needle3 = "issip";

    cout << strStr(haystack3, needle3);

}
