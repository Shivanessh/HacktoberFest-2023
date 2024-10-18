#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Two-pointer approach
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }

    // Recursive approach
    int maxAreaRecursive(vector<int>& height) {
        return maxAreaRecursiveHelper(height, 0, height.size() - 1);
    }

    // Helper function for recursion
    int maxAreaRecursiveHelper(vector<int>& height, int left, int right) {
        if (left >= right) {
            return 0;
        }
        
        int h = min(height[left], height[right]);
        int w = right - left;
        int area = h * w;

        // Max area from the current state and recursive calls
        return max(area, max(maxAreaRecursiveHelper(height, left + 1, right),
                             maxAreaRecursiveHelper(height, left, right - 1)));
    }
};

int main() {
    Solution solution;
    
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result1 = solution.maxArea(height1);
    cout << "Maximum area (Two-pointer): " << result1 << endl;

    vector<int> height2 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result2 = solution.maxAreaRecursive(height2);
    cout << "Maximum area (Recursive): " << result2 << endl;

    return 0;
}
