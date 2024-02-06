#include <iostream>
#include <vector>

using ull = unsigned long long;

ull exp_sum(unsigned int n) {
    std::vector<ull> partitions(n + 1, 0);
    partitions[0] = 1;

    for (unsigned int i = 1; i <= n; i++) {
        for (int j = i; j <= n; ++j) {
            partitions[j] += partitions[j - i];
        }
    }

    return partitions[n];
}
