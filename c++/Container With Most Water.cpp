#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Two-pointer approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h * w;
            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

// Recursive approach
class SolutionRecursive {
public:
    int maxArea(vector<int>& height) {
        return maxAreaRecursive(height, 0, height.size() - 1);
    }

    int maxAreaRecursive(vector<int>& height, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int h = min(height[left], height[right]);
        int w = right - left;
        int area = h * w;

        return max(area, max(maxAreaRecursive(height, left + 1, right), 
                             maxAreaRecursive(height, left, right - 1)));
    }
};

int main() {
    Solution solution;
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum area (Two-pointer): " << solution.maxArea(height1) << endl;

    SolutionRecursive recursiveSolution;
    cout << "Maximum area (Recursive): " << recursiveSolution.maxArea(height1) << endl;

    vector<int> height2 = {1, 1};
    cout << "Maximum area (Two-pointer): " << solution.maxArea(height2) << endl;
    cout << "Maximum area (Recursive): " << recursiveSolution.maxArea(height2) << endl;

    return 0;
}
