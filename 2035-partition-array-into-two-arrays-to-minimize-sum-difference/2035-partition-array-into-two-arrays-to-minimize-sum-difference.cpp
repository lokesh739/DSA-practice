class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        // dp[k] = set of possible sums using exactly k elements
        vector<unordered_set<int>> dp(n / 2 + 1);
        dp[0].insert(0);

        for (int num : nums) {
            for (int k = n / 2 - 1; k >= 0; k--) {
                for (int s : dp[k]) {
                    dp[k + 1].insert(s + num);
                }
            }
        }

        int ans = INT_MAX;
        for (int s : dp[n / 2]) {
            int sum1 = s;
            int sum2 = totalSum - s;
            ans = min(ans, abs(sum1 - sum2));
        }
        return ans;
    }
};
