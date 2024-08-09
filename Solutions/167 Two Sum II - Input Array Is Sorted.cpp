#include <vector>


//Using two pointers and a sorted array we move them if the sum of the values is less or more than target.
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        bool found = false;
        while (!found)
        {
            int sum = numbers[left] + numbers[right];
            if (sum < target)
            {
                left++;
            }
            else if(sum > target){
                right--;
            }
            else
            {
                found = true;
            }

        }

        return {left + 1, right + 1};
    }
};