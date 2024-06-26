#include <string>

using namespace std;

bool is_palindrome(std::string s) {
    // WRITE YOUR BRILLIANT CODE HERE
    int r = s.size() - 1;
    int l = 0;

    while(l <= r) {
        while (l < r && !isalnum(s[l])) {
            l++;
        }
        while (l < r && !isalnum(s[r])) {
            r--;
        }

        if (tolower(s[l]) != tolower(s[r])) return false;

        l++, r--;
    }
    return true;

}