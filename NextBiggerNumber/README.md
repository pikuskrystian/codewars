```c++
#include <iostream>
#include <algorithm>
```
These lines include necessary header files for input/output operations (iostream) and algorithms (algorithm) since the code uses functions from the <algorithm> header.
```c++
std::string sortedDigits(int n) {
    std::string str = std::to_string(n);
    std::sort(str.begin(), str.end(), std::greater<char>());
    return str;
}
```
