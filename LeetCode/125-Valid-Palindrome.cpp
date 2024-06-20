#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {

    if (s.size() == 1) return true;

    string str;

    for (int i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') ||
       (s[i] >= 'A' && s[i] <= 'Z') ||
       (s[i] >= '0' && s[i] <= '9'))
        {
            str += tolower(s[i]);
        }
    }


    if (str.size() == 1 || str.empty() ) return true;

    int end = str.size() - 1;

    for (int i = 0; i <= end; i++) {

        if (str[i] == str[end]) {
            end--;
        } else {
            return false;
        }
    }
    return true;
}


int main() {


    cout << isPalindrome("race a car");


}
