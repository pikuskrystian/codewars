#include <iostream>
#include <string>
#include <map>

class RomanHelper {
public:
    std::string to_roman(unsigned int n) {
        std::string result = "";
        std::map<int, std::string, std::greater<int>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        for (const auto& pair : romanMap) {
            while (n >= pair.first) {
                result += pair.second;
                n -= pair.first;
            }
        }

        return result;
    }

    int from_roman(std::string rn) {
        std::map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int prevValue = 0;

        for (auto it = rn.rbegin(); it != rn.rend(); ++it) {
            int value = romanMap[*it];

            if (value < prevValue) {
                result -= value;
            } else {
                result += value;
            }

            prevValue = value;
        }

        return result;
    }
} RomanNumerals;
