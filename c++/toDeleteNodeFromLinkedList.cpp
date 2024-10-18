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
        
        // In case no majority element is found (though the problem guarantees one), return -1
        return -1;  // or any other indication of failure
    }
};

// Example usage of the majorityElement function
int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3}; // Example input array
    int result = solution.majorityElement(nums); // Call the function
    
    cout << "Majority Element: " << result << endl; // Output the result
    
    return 0; // Indicate successful completion
}
