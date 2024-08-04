#include "Solutions/659 Encode and Decode Strings.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Solution Sol;

    vector<string> input1 = {"neet", "code", "love", "you"};
    vector<string> input2 = {"we", "say", ":", "yes"};
    vector<string> input3 = {"VeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimes"};


    //Sol.topKFrequent(input1, input2);
    //Sol.topKFrequent(input3, input4);
    string encoded = Sol.encode(input3);
    vector<string> decoded = Sol.decode(encoded);
    return 0;
}