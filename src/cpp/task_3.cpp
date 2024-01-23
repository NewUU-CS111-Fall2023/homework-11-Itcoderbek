#include <iostream>
#include <vector>
#include <unordered_set>

bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
    int n = s.length();
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

    // dp[i] represents whether the substring s[0...i-1] can be segmented
    std::vector<bool> dp(n + 1, false);
    dp[0] = true; // An empty string can always be segmented

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            // Check if the substring s[j...i-1] can be segmented and if s[0...j-1] is already segmented
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break; // No need to check further for the current i
            }
        }
    }

    return dp[n];
}

int main() {
    // Example usage
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};

    bool result = wordBreak(s, wordDict);

    std::cout << "Can the string be segmented? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
