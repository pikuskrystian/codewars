class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, result = 0;

        // Step 1: Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check the sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits and handle overflow/underflow
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow/underflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

