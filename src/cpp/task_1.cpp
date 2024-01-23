#include <iostream>
#include <vector>

int countWaysToEvaluateToTarget(const std::vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;
    std::function<void(int, int)> backtrack = [&](int index, int currentSum) {
        if (index == n) {
            
            if (currentSum == target) {
                count++;
            }
            return;
        }
        backtrack(index + 1, currentSum + nums[index]);
        backtrack(index + 1, currentSum - nums[index]);
    };

    backtrack(0, 0);

    return count;
}

int main() {
    // Example usage
    std::vector<int> nums = {2, 1};
    int target = 1;

    int result = countWaysToEvaluateToTarget(nums, target);

    std::cout << "Number of different expressions that evaluate to target: " << result << std::endl;

    return 0;
}
