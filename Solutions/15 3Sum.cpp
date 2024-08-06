#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;

        if(nums.size() < 3){    //Base case 1
            return out;
        }
        if(nums[0] > 0){        //Base case 2
            return out;
        }

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1])//Ignore repetitions
            {
                continue;
            }


            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    vector<int> add = {nums[i], nums[left], nums[right]};
                    out.push_back(add);

                    int last_low_occurence = nums[left] , last_high_occurence = nums[right];
                    while (left < right && nums[left] == last_low_occurence)
                    {
                        left++;
                    }

                    while (left < right && nums[right - 1] == last_high_occurence)
                    {
                        right--;
                    }
                }
            }
        }
        return out;
    }
};