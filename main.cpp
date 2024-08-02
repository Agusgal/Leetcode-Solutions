#include "128-Longest-Consecutive-Sequence.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Solution Sol;
    std::vector<int> input1 = {100,4,200,1,3,2};
    std::vector<int> input2 = {0,3,7,2,5,8,4,6,0,1};
    std::vector<int> input3 = {0, 1, 2, 3, 100, 200, 201, 202, 203, 204, 205, 206};
    std::vector<int> input4 = {0, 1, 1, 2};

    std::cout << Sol.longestConsecutive(input1) << std::endl;
    std::cout << Sol.longestConsecutive(input2) << std::endl;
    std::cout << Sol.longestConsecutive(input3) << std::endl;
}