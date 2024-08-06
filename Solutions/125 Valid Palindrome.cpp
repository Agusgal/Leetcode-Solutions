#include <string>
#include <iostream>


// First we parse to lowercase alphanumeric, then we loop until the middle of the string, if two characters are different retunr false.
// Complexity o(n) in time but we use auxiliary string for memory o(k)
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {

        string lowerString = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                lowerString += tolower(s[i]);
            }
        }
        //cout << lowerString << endl;
        if (lowerString == "")
        {
            return true;
        }

        int right = lowerString.size() - 1;
        for (int left = 0; left < lowerString.size()/2; left++)
        {
            if (lowerString[left] != lowerString[right]) {
                return false;
            }
            right--;
        }

        return true;
    }
};


// Using isalnum we check for alphanumeric numbers only.
// No aux string is used, only pointers.
class Solution2 {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (!isalnum(s[left]) && left < right) {
                left++;
            }
            while (!isalnum(s[right]) && left < right) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};