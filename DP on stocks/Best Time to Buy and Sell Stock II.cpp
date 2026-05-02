// Recursive approach
TC: O(2^n)
SC: O(n)

class Solution {
public:
    int n;
    int solve(int idx, int buy, vector<int>& prices){
        if(idx == n) return 0;

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + solve(idx + 1, 0, prices), solve(idx + 1, 1, prices));
        }else{
            profit = max(prices[idx] + solve(idx + 1, 1, prices), solve(idx + 1, 0, prices));
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return solve(0, 1, prices);
    }
};

// Memoization
class Solution {
public:
    int n;
    int dp[30001][2];

    int solve(int idx, int buy, vector<int>& prices){
        if(idx == n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + solve(idx + 1, 0, prices), solve(idx + 1, 1, prices));
        }else{
            profit = max(prices[idx] + solve(idx + 1, 1, prices), solve(idx + 1, 0, prices));
        }

        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, prices);
    }
};

// bottom-up

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int idx = n - 1; idx >= 0; idx--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;
                if(buy){
                   profit = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                }else{
                    profit = max(prices[idx] + dp[idx + 1][1], dp[idx + 1][0]);
                }

                dp[idx][buy] = profit;
            }
        }
        // retur solve(0, 1, prices) which becomes dp[0][1];
        return dp[0][1];
    }
};

// Peak-valley accumulation (optimal)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;

        for(int i = 1; i < n; i++){
            int cost = prices[i] - prices[i - 1];
            if(cost > 0) profit += cost;
        }

        return profit;
    }
};
