// Recursion 

class Solution {
public:
    int n;
    int solve(int idx, int buy, int k, vector<int>& prices){
        if(idx == n || k == 0) return 0;

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + solve(idx + 1, 0, k, prices), solve(idx + 1, 1, k, prices));
        } else {
            profit = max(prices[idx] + solve(idx + 1, 1, k - 1, prices), solve(idx + 1, 0, k, prices));
        }

        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();

        return solve(0, 1, k, prices);
    }
};

// memoization

class Solution {
public:
    int n;
    int dp[1001][101][2];

    int solve(int idx, int buy, int k, vector<int>& prices){
        if(idx == n || k == 0) return 0;

        if(dp[idx][k][buy] != -1) return dp[idx][k][buy];

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + solve(idx + 1, 0, k, prices), solve(idx + 1, 1, k, prices));
        } else {
            profit = max(prices[idx] + solve(idx + 1, 1, k - 1, prices), solve(idx + 1, 0, k, prices));
        }

        return dp[idx][k][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, k, prices);
    }
}; 

// bottom-up
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for(int idx = n - 1; idx >= 0; idx--){
            for(int t = 1; t <= k; t++){
                for(int buy = 0; buy < 2; buy++){
                    int profit = 0;

                    if(buy){
                        profit = max(-prices[idx] + dp[idx + 1][t][0], dp[idx + 1][t][1]);
                    } else {
                        profit = max(prices[idx] + dp[idx + 1][t - 1][1], dp[idx + 1][t][0]);
                    }

                    dp[idx][t][buy] = profit;
                }
            }
        }

        return dp[0][k][1];
    }
};
