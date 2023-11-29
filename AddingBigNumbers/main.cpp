#include <string>

std::string add(const std::string& a, const std::string& b) {
  std::string result;
  int carry = 0;
  int i = a.length() - 1, j = b.length() - 1;

  while (i >= 0 || j >= 0 || carry > 0) {
    int digitSum = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
    result.insert(result.begin(), digitSum % 10 + '0');
    carry = digitSum / 10;
  }

  return result;
}
