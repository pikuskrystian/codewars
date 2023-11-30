#include <iostream>
#include <vector>
#include <algorithm>

std::string sortedDigits(int n) {
    std::string str = std::to_string(n);
    std::sort(str.begin(), str.end(), std::greater<char>());
    return str;
}

int nextBigger(int n) {
    std::string maxStr = sortedDigits(n);
    int max = std::stoi(maxStr);

    for (int i = n + 1; i <= max; i++) {
        if (max == std::stoi(sortedDigits(i))) {
            return i;
        }
    }

    return -1;
}
