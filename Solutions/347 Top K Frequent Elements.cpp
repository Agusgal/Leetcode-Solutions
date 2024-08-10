#include <vector>
#include <unordered_map>

using namespace std;

//Using Bucket sort and a map is posible to solve this problem.
//First it is necessary to create a map of keys with their frequency.
//Then qe map that map with a bucket to sort the most frequent numbers.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numbersMap;
        vector<vector<int>> valueList;

        for (auto num: nums) {
            numbersMap[num] += 1;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto pair:numbersMap)
        {
           bucket[pair.second].push_back(pair.first);
        }

        vector<int> out;
        for (int i = nums.size(); i >= 0; i--)
        {
            if (out.size() >= k)
            {
                break;
            }

            if (!bucket[i].empty()) {
                out.insert(out.end(), bucket[i].begin(), bucket[i].end());
            }
        }

        return out;
    }

};