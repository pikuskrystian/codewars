#include <cstdint>
#include <vector>
#include <algorithm>

uint64_t hamber(int n) {
    if (n <= 0) {
        return 1;
    }

    std::vector<uint64_t> hamming_numbers(n);
    hamming_numbers[0] = 1;

    int i = 0, j = 0, k = 0;

    for (int x = 1; x < n; ++x) {
        uint64_t next_hamming = std::min({hamming_numbers[i] * 2, hamming_numbers[j] * 3, hamming_numbers[k] * 5});
        hamming_numbers[x] = next_hamming;

        if (next_hamming == hamming_numbers[i] * 2) {
            ++i;
        }
        if (next_hamming == hamming_numbers[j] * 3) {
            ++j;
        }
        if (next_hamming == hamming_numbers[k] * 5) {
            ++k;
        }
    }

    return hamming_numbers.back();
}
