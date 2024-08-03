#include "Solutions/242 Valid Anagram.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Solution Sol;

    std::string input1 = "anagram";
    std::string input2 = "nagaram";

    std::string input3 = "rat";
    std::string input4 = "car";

    std::string input5 = "abcd";
    std::string input6 = "dcbb";


    std::cout << Sol.isAnagram(input1, input2) << std::endl;
    std::cout << Sol.isAnagram(input3, input4) << std::endl;
    std::cout << Sol.isAnagram(input5, input6) << std::endl;
}