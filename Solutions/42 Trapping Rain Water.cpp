#include <vector>
#include <algorithm>

// This solution works, but for large inputs it exceeds time due to its algorithmic complexity.
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {


        int water = 0;
        vector<vector<int>> neighbours;

        if (height.size() <= 2){
            return water;
        }

        int center = 0;
        int right = 1;
        int left = 0;

        //find highest neighbours
        while(center < height.size()){
            while((right < height.size()) && height[right] <= height[center]){
                right++;
            }

            if (right == height.size()){
                right = -1;
            }

            while((left >= 0) && (height[left] <= height[center])){
                left--;
            }


            neighbours.push_back({left, right});
            center++;
            right = center + 1;
            left = center - 1;
        }

        vector<vector<int>> used;
        for (int i = 0; i < neighbours.size(); i++){
            int leftIdx = neighbours[i][0];
            int rightIdx = neighbours[i][1];

            if ((leftIdx == -1) || (rightIdx == -1)){
                continue;
            }

            vector<int> temp;
            temp.push_back(leftIdx);
            temp.push_back(rightIdx);
            if (find(used.begin(), used.end(), temp) != used.end()){
                continue;
            } else{
                used.push_back(temp);
            }


            int mini = min(height[leftIdx], height[rightIdx]);
            int h = height[i];
            int add = (rightIdx - leftIdx - 1) * (mini - h);
            water += add;
       }

       return  water;
    }
};

// Using the same idea of searching for local max centered arround a value
// The water level contained is given by the lowest of the max values centered arround the ith cell.
// if the left value is less than the rogth value then left is moved and water is added if the next cell is lower than maxleft.
// The same is done for the right limit.
// It has o(n) time complexity and o(k) memory compelxity.
class Solution2 {
public:
    int trap(vector<int>& height) {

        int water = 0;

        if (height.size() <= 2){
            return water;
        }

        int left = 0;
        int right = height.size() - 1;

        int maxLeft = height[left];
        int maxRight = height[right];

        while (left < right) {
            if (maxLeft <= maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
            }
            else{
                right--;
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
            }
        }

        return water;

    }
};