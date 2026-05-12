// Recursive

class Solution {
public:
    int solve(int n, vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(n <= 0) return 1e9;

        int take = 1e9;
        if(coins[n - 1] <= amount){
            take = 1 + solve(n, coins, amount - coins[n - 1]);
        }

        int skip = solve(n - 1, coins, amount);

        return min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int ans = solve(n, coins, amount);

        return ans >= 1e9 ? -1 : ans;
    }
};

// Top-Down

class Solution {
public:
    int dp[13][10001];
    int solve(int n, vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(n <= 0) return 1e9;

        if(dp[n][amount] != -1) return dp[n][amount];

        int take = 1e9;
        if(coins[n - 1] <= amount){
            take = 1 + solve(n, coins, amount - coins[n - 1]);
        }

        int skip = solve(n - 1, coins, amount);

        return dp[n][amount] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(n, coins, amount);

        return ans >= 1e9 ? -1 : ans;
    }
};

// Bottom-Up
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int idx = 1; idx <= n; idx++){
            for(int amt = 0; amt <= amount; amt++){
                int take = 1e9;
                if(coins[idx - 1] <= amt){
                    take = 1 + dp[idx][amt - coins[idx - 1]];
                }

                int skip = dp[idx - 1][amt];

                dp[idx][amt] = min(take, skip);
            }
        }
        int ans = dp[n][amount];

        return ans >= 1e9 ? -1 : ans;
    }
};
