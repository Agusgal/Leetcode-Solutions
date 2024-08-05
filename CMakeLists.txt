cmake_minimum_required(VERSION 3.21)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(Leetcode
                "Solutions/1 Two Sum.cpp"
                "Solutions/5 Longest Palindromic Substring.cpp"
                "Solutions/3 Longest Substring Without Repeating Characters.cpp"
                "Solutions/49 Group Anagrams.cpp"
                "Solutions/128 Longest Consecutive Sequence.cpp"
                "Solutions/217 Contains Duplicate.cpp"
                "Solutions/238 Product of Array Except Self.cpp"
                "Solutions/242 Valid Anagram.cpp"
                "Solutions/347 Top K Frequent Elements.cpp"
                "Solutions/659 Encode and Decode Strings.cpp"
                main.cpp)

