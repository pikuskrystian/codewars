class Solution {
public:
    int romanToInt(string s) {
        // Function to get the value of a Roman numeral
        auto getValue = [](char ch) -> int {
            switch (ch) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0; // Should not happen
            }
        };

        int total = 0;
        int prevValue = 0;

        // Loop through the string in reverse
        for (int i = s.size() - 1; i >= 0; --i) {
            int currentValue = getValue(s[i]);

            // If current value is less than the previous value, subtract it
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                // Otherwise, add it
                total += currentValue;
            }

            // Update previous value
            prevValue = currentValue;
        }

        return total;
    }
};

