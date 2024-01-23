#include <iostream>
#include <vector>
#include <numeric>

bool canPartition(std::vector<int>& nums) {
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

    // If the total sum is odd, it's not possible to partition into two equal subsets
    if (totalSum % 2 != 0) {
        return false;
    }
    int targetSum = totalSum / 2;
    int n = nums.size();

    // dp[i][j] represents whether a subset of the first i elements can form a sum j
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    // Base case: an empty subset can always form a sum of 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            // If the current element is greater than the target sum, it cannot be included
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {

                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][targetSum];
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 5, 11, 5};

    bool result = canPartition(nums);

    std::cout << "Can the array be partitioned into two subsets with equal sum? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
