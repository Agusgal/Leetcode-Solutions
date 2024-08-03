#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>


//Solución poco eficiente.
class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxLen = 0;
        int localLen = 0;
        std::map<char, int> charMap;

        if (s.empty())
        {
            return maxLen;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if (charMap.find(s[i]) == charMap.end())
            {
                charMap.insert({s[i], i});
                localLen += 1;
                maxLen = std::max(localLen, maxLen);
            }
            else
            {
                i = charMap.find(s[i])->second + 1;
                charMap.clear();

                charMap.insert({s[i], i});
                localLen = 1;
            }
        }
        return maxLen;
    }
};


//Solución más eficiente usando indicadores left-right.
//Usar set.find en vez de set.count al principio hace que corra más rápido.
class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLen = 0;
        std::unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charSet.find(s[right]) == charSet.end())
            {
                charSet.insert(s[right]);
                maxLen = std::max(maxLen, right - left + 1);
            }
            else
            {
                while (charSet.find(s[right]) != charSet.end() )
                {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLen;
    }
};


//Solucion más eficiente en memoria usando maps en vez de sets.
class Solution3 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLen = 0;
        std::unordered_map<char, int> charMap;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLen = std::max(maxLen, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }

        return maxLen;
    }
};

// Solución más eficiente en memoria y complejidad usando arreglos de tamaño definido.
// Uso arreglo de 256 ints, cada int representa la posición de un char, de ahi el tamaño
// Uso una sliding window con start como indice.
// Si el índice del char es mayor al comienzo de la ventana la actualizo, si no sigue creciendo.
class Solution4{
public:
    int lengthOfLongestSubstring(const std::string& str)
    {
        if (str.length() == 0)
        {
            return 0;
        }

        std::vector<int> seen(256, 0);
        int maxLen = 1;
        for (int i = 0, start = 0; i < str.length(); i++) {
            int seenIndex = seen[str[i]];
            if (seenIndex > start)
            {
                start = seenIndex;
            }
            maxLen = std::max(maxLen, i - start + 1);
            seen[str[i]] = i + 1;
        }
        return maxLen;
    }
};