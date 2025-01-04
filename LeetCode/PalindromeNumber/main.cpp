class Solution {
public:
    bool isPalindrome(int x) {
    // Negative numbers or numbers ending in 0 (but not 0 itself) cannot be palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) 
        return false;

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // Check if the number is equal to its reverse (for odd lengths, remove middle digit)
    return x == reversed || x == reversed / 10;
}

};
