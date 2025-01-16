class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Return empty if no strings
        
        // Start with the first string as the prefix
        string prefix = strs[0];
        
        // Compare the prefix with each string in the array
        for (int i = 1; i < strs.size(); ++i) {
            // Trim the prefix until it matches the current string
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return ""; // No common prefix
            }
        }
        
        return prefix;
    }
};

