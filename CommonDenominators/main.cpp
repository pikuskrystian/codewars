#include <vector>
#include <numeric>
#include <sstream>

class Fracts {
public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst) {
        // find the least common multiple of all denominators
        unsigned long long lcm = 1;
        for (auto &frac : lst) {
            lcm = std::lcm(lcm, frac[1]);
        }
        
        // convert each fraction to the common denominator
        std::vector<std::vector<unsigned long long>> result;
        for (auto &frac : lst) {
            unsigned long long n = frac[0] * (lcm / frac[1]);
            result.push_back({n, lcm});
        }
        
        // convert result to string
        std::ostringstream oss;
        for (auto &frac : result) {
            oss << "(" << frac[0] << "," << frac[1] << ")";
        }
        return oss.str();
    }
};
