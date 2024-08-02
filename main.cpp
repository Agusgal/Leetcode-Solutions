#include "Solutions/3-Longest Substring Without Repeating Characters.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Solution Sol;

    std::string input1 = "anviaj";
    std::string input2 = "bbbbb";
    std::string input3 = "pwwkew";
    std::string input4 = "dvdf";

    std::cout << Sol.lengthOfLongestSubstring(input1) << std::endl;
    std::cout << Sol.lengthOfLongestSubstring(input2) << std::endl;
    std::cout << Sol.lengthOfLongestSubstring(input3) << std::endl;
    std::cout << Sol.lengthOfLongestSubstring(input4) << std::endl;
}