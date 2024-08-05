#include <vector>

// The brute solution, a nested loop would be o(n^2) so we must find another one.
// One possibility is calculating prefix and suffix vectors, then multiplicating them.
// Other possibility is using division, getting the greatest multiplication and then dividing over the values of the vector.
// Using division fails when 0 is allowed.
// This solution has o(n) time complexity and o(n) memory complexity.
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int Len = nums.size();
        vector<int> prefix(Len, 1);
        vector<int> suffix(Len, 1);

        for(int i = 1; i < Len; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for(int i = Len - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> out(Len, 1);
        for(int i = 0; i < Len; i++) {
            out[i] = prefix[i] * suffix[i];
        }
        return out;
    }
};

// To get o(1) complexity we store the values in the out answer vector
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int Len = nums.size();
        vector<int> out(Len, 1);

        int prefix = 1;
        for (int i = 0; i < Len; i++) {
            out[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for (int i = Len - 1; i >= 0; i--) {
            out[i] = out[i] * postfix;
            postfix = postfix * nums[i];
        }

        return out;
    }
};