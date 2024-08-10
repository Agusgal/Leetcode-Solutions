cmake_minimum_required(VERSION 3.21)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(Leetcode
                "Solutions/1 Two Sum.cpp"
                "Solutions/5 Longest Palindromic Substring.cpp"
                "Solutions/3 Longest Substring Without Repeating Characters.cpp"
                "Solutions/11 Container With Most Water.cpp"
                "Solutions/15 3Sum.cpp"
                "Solutions/36 Valid Sudoku.cpp"
                "Solutions/42 Trapping Rain Water.cpp"
                "Solutions/49 Group Anagrams.cpp"
                "Solutions/121 Best Time to Buy And Sell Stock.cpp"
                "Solutions/125 Valid Palindrome.cpp"
                "Solutions/128 Longest Consecutive Sequence.cpp"
                "Solutions/167 Two Sum II - Input Array Is Sorted.cpp"
                "Solutions/217 Contains Duplicate.cpp"
                "Solutions/238 Product of Array Except Self.cpp"
                "Solutions/242 Valid Anagram.cpp"
                "Solutions/347 Top K Frequent Elements.cpp"
                "Solutions/424 Longest Repeating Character Replacement.cpp"
                "Solutions/659 Encode and Decode Strings.cpp"
                main.cpp)

