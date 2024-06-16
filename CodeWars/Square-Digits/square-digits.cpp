int square_digits(int num) {
    vector<int>v;

    while (num != 0) {
        int n = (num % 10) * (num % 10);
        v.insert(v.begin(), n);
        num /= 10;
    }
    string result;
    for (int i : v) {
        result += to_string(i);
    }

    return atoi(result.c_str());
}