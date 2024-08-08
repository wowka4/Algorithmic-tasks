string reverseWords(const string& s) {
    string res;
    string word;
    for (const char c : s) {
        if (c == ' ') {
            res += (word + " ");
            word.clear();
        } else {
            word = c + word;
        }
    }
    if (!word.empty()) {
        res += word;
    }
    return res;
}