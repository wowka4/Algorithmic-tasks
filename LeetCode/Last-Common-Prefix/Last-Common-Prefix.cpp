#include <iostream>
#include <string>
#include <vector>

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0){
        return "";
    }
    if (strs.size() == 1){
        return strs[0];
    }

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {

        string current = strs[i];
        int coincidence = 0;
        int reader = 0;

        while ( (reader < current.size()) && (reader < prefix.size()) ) {

            if (current[reader] == prefix[reader]) {
                coincidence++;
                reader++;
            } else {
                break;
            }
        }
        prefix = prefix.substr(0, coincidence);
    }
    return prefix;
}

int main() {
    vector<string> v = {"dog","racecar","car"};

    cout << longestCommonPrefix(v);
}
