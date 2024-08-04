#include <string>
#include <vector>

// To encode and decode it is necessary to encode the origianl strings data inside a single string
// Here the last char represents how many strings the original list had, kets say n.
// Then the next n chars (roight to left ) represent the lenghts of the string.
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        vector<char> strLen;
        for(auto str: strs)
        {
            out += str;
            strLen.push_back((char)str.size());
        }

        for (auto len: strLen)
        {
            out += len;
        }

        out += (char)strs.size();
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        int stringCount = s[s.size() - 1];
        int position = 0;

        for (int i = s.size() - stringCount - 1; i < s.size() - 1; i++)
        {
            unsigned char stringLen = s[i];
            out.push_back(s.substr(position, (int)stringLen));
            position += stringLen;
        }

        return out;
    }
};

// Another posible solutions is putting a synch integers followed by a standard delimeter.
// If we always start by an integer followed by a delimiter it is easy to follow the format no matter the string.
// Solution provided by Neetcode.
class Solution2 {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }

        return result;
    }
private:
};
