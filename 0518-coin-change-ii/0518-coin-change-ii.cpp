class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                prev[t] = 1;
        }

        for (int i = 1; i < n; i++) {
            curr = prev; // copy for current iteration
            for (int target = 0; target <= amount; target++) {
                long long take = 0;
                if (coins[i] <= target) 
                    take = curr[target - coins[i]]; // using same row (unbounded knapsack)
                curr[target] = prev[target] + take;
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};
