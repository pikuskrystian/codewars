class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        // Helper function for backtracking
        function<void(int, string)> backtrack = [&](int index, string current) {
            // If the current combination is complete
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            // Get the letters corresponding to the current digit
            string letters = digitToLetters[digits[index] - '0'];
            for (char letter : letters) {
                // Add the letter and recurse
                backtrack(index + 1, current + letter);
            }
        };

        backtrack(0, "");

        return result;
    }
};

