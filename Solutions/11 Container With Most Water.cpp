#include <vector>
#include <algorithm>

using namespace std;



// Using left and right pointers it is possible to solve the problem without brute force.
// The highest area is stored and then in order to iterate over the array only the highest height is considered.
// The lowest can be discarded, because the water level would be lower, thus the area will be inferior.
// This is a kind of greedy algorithm.
class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        if (height.size() == 2){
            return min(height[0], height[1]);
        }

        int startingArea = (right - left) * (min(height[left], height[right]));
        int maxArea = startingArea;

        while (left < right) {

            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(area, maxArea);

            if (height[left] > height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxArea;
    }
};