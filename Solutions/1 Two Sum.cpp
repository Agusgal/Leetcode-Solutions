#include <vector>
#include <unordered_map>

//This solution is really efficient in memory but o(n^2) in computational complexity.
class Solution {
public:
   std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector <int> indices;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                }
            }
        }

        return indices;
    }
};

//Using a map to store values and indexes ond calculating compelment only one loop is used.
class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numMap; //number and index

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end())
            {
                return {i, numMap[complement]};
            }
            numMap.insert({nums[i], i});
        }
        return {};
    }
};