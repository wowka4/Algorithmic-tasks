#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int n;
    cin >> n;

    char arr[n][n];

    int star_row = 0;
    int star_col = n - 1;
    int one_row = 1;
    int one_col = n - 1;
    int one_count = 0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == star_row && j == star_col) {
                arr[i][j] = '1';
            } else if (i == one_row && j == one_col) {
                while (j < n) {
                    arr[i][j] = '2';
                    j++;
                }
                --j;
                ++one_count;
                --one_col;
                ++one_row;
            } else {
                arr[i][j] = '0';
            }
        }
        --star_col, ++star_row;
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j];
        }
        cout << endl;
    }

}