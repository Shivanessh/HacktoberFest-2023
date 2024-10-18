#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate;
        int n = nums.size();
        
        // Phase 1: Find a candidate for the majority element
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        // Phase 2: Verify that the candidate is indeed the majority element
        cnt = 0;  // Reset count to verify
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate) {
                cnt++;
            }
        }
        
        // Check if the candidate is the majority element
        if (cnt > n / 2) {
            return candidate;
        }
        
        return -1;  // or any other indication of failure
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};  // Example input
    int result = solution.majorityElement(nums);
    cout << "Majority Element: " << result << endl;  // Output the result
    return 0;
}
