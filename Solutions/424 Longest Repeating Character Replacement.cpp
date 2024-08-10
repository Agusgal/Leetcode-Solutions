#include <string>
#include <vector>
using namespace std;


// For some reason beyond my comprehension this algorithm does not work.
class Solution {
public:
    int characterReplacement(string s, int k) {

        if (s.size() == 1){
            return 1;
        }

        int maxLen = 1;
        int len = 0;
        int start = 0;
        int end = 0;
        int changes = k;

        while(end < s.size()){

            if ((s[start] != s[end]) && (s[end] == s[end + 1]) && changes){
                changes--;
                s[start] = s[end];
                len++;
                maxLen = max(maxLen, len);
            }
            else if ((s[start] != s[end]) && changes){
                s[end] = s[start];
                changes--;
                len++;
                maxLen = max(maxLen, len);
            }
            else if (s[start] == s[end]){
                len++;
                maxLen = max(maxLen, len);
            }
            else{
                maxLen = max(maxLen, len);
                len = 1;
                changes = k;
                start = end;
            }


            end++;
        }

        return maxLen;
    }
};


//This solution uses the maxF optimization.
// maxCharCount store the character with the most frequency.
// if the window size - most frequent char is more than the most replacement that can be made then the widnow size must be decremented.
// else the window size can be incremented.
// Another more simple solution would be to iterate over the whole hashmap, that solution would be o(26 * n)
// This one is o(n)
class Solution2 {
public:
    int characterReplacement(string s, int k) {

        //Array to count how many times each char appears, acces by char decimal value,
        vector<int> count(26, 0);
        int start = 0;
        int end = 0;

        int maxCharCount = 0;
        int result = 0;

        while (end < s.size()) {
            //Add appearance of a character
            count[s[end] - 'A']++;

            //update max count
            maxCharCount = max(maxCharCount, count[s[end] - 'A']);

            //check is window size minus repeated character is more than limit k
            if (end - start + 1 - maxCharCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            result = max(result, end - start + 1);
            end++;

        }

        return result;
    }
};
