#include <vector>
#include <unordered_set>

//Solution that uses sets, if new elements appears, save it on set. When duplicate appears return true.
//USing nested loops the solution would be o(n^2), sorting and then searching o(nlog(n)) can be achieved
//This solution achieves o(n) using sets. The for loop goes over
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> numbers;

        for(auto el: nums)
        {
            if(numbers.find(el) == numbers.end())
            {
                numbers.insert(el);
            }
            else {
                return true;
            }
        }
        return false;
    }
};