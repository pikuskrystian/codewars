class Solution {
public:
    bool isMatch(string s, string p) {
         int m = s.size(), n = p.size();
    // Create a DP table where dp[i][j] is true if s[0...i-1] matches p[0...j-1]
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

    // Base case: empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns like a*, a*b*, a*b*c*
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                // Characters match or pattern has '.'
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' can match zero or more of the previous character
                dp[i][j] = dp[i][j - 2] || 
                           ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
    }
};
