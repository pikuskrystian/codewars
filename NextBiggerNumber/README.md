# Breaking down of the C++ code step by step:
```c++
#include <iostream>
#include <algorithm>
```
These lines include necessary header files for input/output operations **(iostream)** and algorithms **(algorithm)** since the code uses functions from the **<algorithm>** header.
```c++
std::string sortedDigits(int n) {
    std::string str = std::to_string(n);
    std::sort(str.begin(), str.end(), std::greater<char>());
    return str;
}
```
This function **sortedDigits**, takes an integer **n** as input and returns a string representing the digits of **n** sorted in descending order. It does this by converting n to a string, sorting the characters in reverse order, and then returning the resulting string.
```c++
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
```

This function, **nextBigger**, finds the next bigger number with the same digits as the input number **n**. Here's the breakdown:

- **std::string maxStr = sortedDigits(n);** : Calls the **sortedDigits** function to get the maximum possible permutation of digits for **n** and stores it as a string.

- **int max = std::stoi(maxStr);** : Converts the string **maxStr** back to an integer to compare with other numbers.

- **for (int i = n + 1; i <= max; i++) {** : Iterates from n + 1 to max to find the next bigger number.

- **if (max == std::stoi(sortedDigits(i))) { return i; }** : Checks if the current number i has the same sorted digits as the maximum permutation. If true, returns **i**.
- **return -1;** : If no such number is found during the iteration, returns -1, indicating that there is no next bigger number with the same digits.
