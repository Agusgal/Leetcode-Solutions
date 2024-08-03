#include <string>
#include <vector>
#include <unordered_map>

// This solution uses a map. Sorted anagrams are the same, so we sort every word and add it to the map.
// Then it is posible to use the sorted word as key to push every string to out vector.
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringMap;

        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            stringMap[word].push_back(x);
        }

        vector<vector<string>> ans;
        for(auto x: stringMap){
            ans.push_back(x.second);
        }
        return ans;
    }
};