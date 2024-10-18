#include <iostream>
using namespace std;

class Solution {
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {
        long long maxSum = arr[0];  // Initialize maxSum to the first element
        long long sum = 0;          // Initialize sum to 0

        for (int i = 0; i < n; i++) {
            sum += arr[i];  // Add the current element to sum
            
            // Update maxSum if the current sum is greater
            if (sum > maxSum) {
                maxSum = sum;
            }
            
            // Reset sum to 0 if it becomes negative
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return maxSum;  // Return the maximum sum found
    }
};

int main() {
    Solution solution;
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array
    
    long long result = solution.maxSubarraySum(arr, n); // Call the function
    cout << "Maximum Subarray Sum: " << result << endl; // Output the result
    
    return 0; // Indicate successful completion
}
