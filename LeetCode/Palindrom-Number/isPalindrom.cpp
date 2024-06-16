class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        long long n = x;
        long long reversed = 0;

        while(n != 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }

        return x == reversed;
    }
};