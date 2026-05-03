// Recursion

class Solution {
public:
    int n;
    int solve(int idx, int buy, vector<int>& prices, int fee){
        if(idx == n) return 0;

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] - fee + solve(idx + 1, 0, prices, fee), solve(idx + 1, 1, prices, fee));
        }else {
            profit = max(prices[idx] + solve(idx + 1, 1, prices, fee), solve(idx + 1, 0, prices, fee));
        }

        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();

        return solve(0, 1, prices, fee);
    }
};

// Memoization
class Solution {
public:
    int n;
    int dp[50001][2];

    int solve(int idx, int buy, vector<int>& prices, int fee){
        if(idx == n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] - fee + solve(idx + 1, 0, prices, fee), solve(idx + 1, 1, prices, fee));
        }else {
            profit = max(prices[idx] + solve(idx + 1, 1, prices, fee), solve(idx + 1, 0, prices, fee));
        }

        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, prices, fee);
    }
}; 

// Bottom-up
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int idx = n - 1; idx >= 0; idx--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;

                if(buy){
                    profit = max(-prices[idx] - fee + dp[idx + 1][0], dp[idx + 1][1]);
                } else {
                    profit = max(prices[idx] + dp[idx + 1][1], dp[idx + 1][0]);
                }

                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//
