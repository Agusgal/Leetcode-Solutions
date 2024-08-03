#include "Solutions/347 Top K Frequent Elements.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Solution Sol;

    std::vector<int> input1 = {1, 1, 1, 2, 2, 3};
    int input2 = 2;

    std::vector<int> input3 = {1};
    int input4 = 1;

    std::vector<int> input5 = {1, 2};
    int input6 = 2;

    //Sol.topKFrequent(input1, input2);
    //Sol.topKFrequent(input3, input4);
    Sol.topKFrequent(input5, input6);

    //std::cout << Sol.groupAnagrams(input1) << std::endl;
    //std::cout << Sol.groupAnagrams(input2) << std::endl;
    //std::cout << Sol.groupAnagrams(input3) << std::endl;
}