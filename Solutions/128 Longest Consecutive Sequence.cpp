#include <vector>
#include <unordered_set>


//Because we used sorting then the time complexity is o(n*log(n))
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        sort(std::begin(nums), std::end(nums));
        int maxLen = 1;
        int localLen = 1;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] == 1)
            {
                localLen += 1;
                if (localLen > maxLen)
                {
                    maxLen = localLen;
                }
            }
            else if(nums[i + 1] == nums[i])
            {
            }
            else
            {
                localLen = 1;
            }
        }


        return maxLen;
    }
};


//This solution by Neetcode has o(n) time complexity because it iterates n times.
// The while loop is not executed every time.
class Solution2 {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(auto &n: s){
            //if this is the start of the sequence
            if(!s.count(n - 1)){
                int length = 1;
                while(s.count(n + length))
                    ++length;
                longest = std::max(longest, length);
            }

        }
        return longest;
    }
};