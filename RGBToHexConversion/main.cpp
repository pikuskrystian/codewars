#include <string>
#include <sstream>
#include <iomanip>

class RGBToHex {
public:
    static std::string rgb(int r, int g, int b) {
        r = std::clamp(r, 0, 255);
        g = std::clamp(g, 0, 255);
        b = std::clamp(b, 0, 255);
    
        std::stringstream ss;
        ss << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << r 
           << std::setw(2) << g << std::setw(2) << b;
        return ss.str();
    }
};
