#include <vector>
#include <algorithm>
using namespace std;


// Using the sliding window with variable size technique,
// if the price to the right is higher, then there are profits. Max profits is stored and the start pointer remains the same.
// The start pointer is only updated when a lower price is found.
// It has a complexity of o(n) and memory complexity of o(k)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int start = 0, end = 0;

        while (end < prices.size()){

            int profit = prices[end] - prices[start];

            if (prices[end] > prices[start]){
                maxProfit = max(maxProfit, profit);
            }
            else{
                start = end;
            }
            end++;
        }

        return maxProfit;
    }
};