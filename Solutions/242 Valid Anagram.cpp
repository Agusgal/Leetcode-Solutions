#include <string>
#include <set>
#include <unordered_map>


//Using multisets we can make two sets each with every character if they are not the same return false.
//Complexity should approach o(n)
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        std::multiset<char> charSet1;
        std::multiset<char> charSet2;

        if (s.length() != t.length())
        {
            return false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            charSet1.insert(s[i]);
            charSet2.insert(t[i]);
        }

        if (charSet1 == charSet2)
        {
            return true;
        }


        return false;
    }
};

// Using a hashmap (unordered map) more efficiency can be achieved.
class Solution2 {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()){
            return false;
        }

        std::unordered_map<char,int> smap;
        std::unordered_map<char,int> tmap;

        for(int i = 0; i < s.size(); i++)
        {
            smap[s[i]]++; //Doing this if the element is not present we insert it, and increment value.
            tmap[t[i]]++;
        }

        for(int i = 0; i < smap.size(); i++){
            if(smap[i] != tmap[i]) return false;
        }
        return true;
    }
};