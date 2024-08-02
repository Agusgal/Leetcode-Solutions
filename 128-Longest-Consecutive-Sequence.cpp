#include <vector>

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