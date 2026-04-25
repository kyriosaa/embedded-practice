class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers are never palindromes
        if(x < 0) {
            return false;
        }

        long reversed = 0;
        int original = x;

        // reconstruct reversed number
        while(x > 0) {
            // anything % 10 will equal the last digit
            reversed = reversed * 10 + x % 10;
            // remove the last digit so the loop can move onto next number
            x /= 10;
        }

        // return if the statement is true
        return original == reversed;
    }
};