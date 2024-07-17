#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs, const map<string, int>& max_amount,
                       map<string, int>& shelter) {
    return count_if(new_dogs.begin(), new_dogs.end(),
        [&max_amount, &shelter](const string& dog) {
            if (shelter[dog] + 1 <= max_amount.at(dog)) {
                shelter[dog]++;
                return true;
            }
            return false;
        });
}

int main() {
    map<string, int> shelter {
                    {"landseer"s, 1},
                    {"otterhound"s, 2},
                    {"pekingese"s, 2},
                    {"pointer"s, 3},
            };

    map<string, int> max_amount {
                    {"landseer"s, 2},
                    {"otterhound"s, 3},
                    {"pekingese"s, 4},
                    {"pointer"s, 7}
    };

    cout << CountAndAddNewDogs({"landseer"s, "otterhound"s, "otterhound"s, "otterhound"s, "pointer"s}, max_amount, shelter) << endl;
}