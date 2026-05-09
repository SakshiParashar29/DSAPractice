// Recursive

class Solution {
public:
    int solve(int n, vector<int>& coins, int amount){
        if(n <= 0) return amount == 0;

        int take = 0;
        if(coins[n - 1] <= amount){
            take = solve(n, coins, amount - coins[n - 1]);
        }

        int skip = solve(n - 1, coins, amount);

        return take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        return solve(n, coins, amount);
    }
};

// Top-down
class Solution {
public:
    int dp[301][5001];
    int solve(int n, vector<int>& coins, int amount){
        if(n <= 0) return amount == 0;

        if(dp[n][amount] != -1) return dp[n][amount];

        int take = 0;
        if(coins[n - 1] <= amount){
            take = solve(n, coins, amount - coins[n - 1]);
        }

        int skip = solve(n - 1, coins, amount);

        return dp[n][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(n, coins, amount);
    }
};
