#include <string>

struct Decoder
{
    static std::string decode(const std::string& p_what)
    {
        using namespace std;

        string w, out, test;
        string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? ";

        int max = p_what.length();

        w.resize(max);
        out.resize(max);
        test.resize(max);

        // Initialize out with the input p_what
        out = p_what;

        for (int ii = 0; ii < 67; ii++)
        {
            // Set w to the current character of the alphabet
            for (int yy = 0; yy < max; yy++)
                w[yy] = alph[ii];

            // Get the encoding for the current character
            test = Encoder::encode(w);

            // Update out based on the match with test
            for (int yy = 0; yy < max; yy++)
            {
                if (p_what[yy] == '-' && out[yy] != '-')
                    continue;  // Skip already modified characters
                if (p_what[yy] == test[yy])
                    out[yy] = w[yy];
            }
        }

        return out;
    }
};
