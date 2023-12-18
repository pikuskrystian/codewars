#include <string>

std::string sum_strings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;

    // Make sure a is the larger number
    if (a.length() < b.length()) {
        return sum_strings(b, a);
    }

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int x = (i >= 0) ? (a[i--] - '0') : 0;
        int y = (j >= 0) ? (b[j--] - '0') : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;

        // Prepend the digit to the result string
        result.insert(result.begin(), '0' + sum);
    }

    return result;
}
