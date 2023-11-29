#include <string>
#include <sstream>

std::string pig_it(std::string str) {
    std::stringstream ss(str);
    std::string word, result;
    
    while (ss >> word) {
        if (isalpha(word[0])) {
            word += word[0];
            word.erase(0, 1);
            result += word + "ay ";
        } else {
            result += word + " ";
        }
    }
    
    result.erase(result.length() - 1); // remove trailing space
    return result;
}
