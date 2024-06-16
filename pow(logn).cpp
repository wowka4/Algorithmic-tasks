

// задача возвести a в степень n за число действий равное Logn
int a = 5;
int n = 5;

int b = 1;
int k = n;
int c = a;

while (k != 0) {
    if (k % 2 == 0) {
        k /= 2;
        c *= c;
    } else {
        k -= 1;
        b *= c;
    }
}

cout << b; // 3125