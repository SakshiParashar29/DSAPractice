// Recursion
TC: O(2^n)
SC: O(n)

class Solution {
public:
    int n;
    int solve(int idx, int canBuy, int transactions, vector<int>& prices){
        if(idx == n || transactions == 0) return 0;

        int profit = 0;

        if(canBuy){
            profit = max(-prices[idx] + solve(idx + 1, 0, transactions, prices), solve(idx + 1, 1, transactions, prices));
        }
        else{
            profit = max(prices[idx] + solve(idx + 1, 1, transactions - 1, prices), solve(idx + 1, 0, transactions, prices));
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return solve(0, 1, 2, prices);
    }
};

// Memoization
class Solution {
public:
    int n;
    int dp[100001][2][3];
    int solve(int idx, int canBuy, int transactions, vector<int>& prices){
        if(idx == n || transactions == 0) return 0;

        if(dp[idx][canBuy][transactions] != -1) return dp[idx][canBuy][transactions];
        int profit = 0;

        if(canBuy){
            profit = max(-prices[idx] + solve(idx + 1, 0, transactions, prices), solve(idx + 1, 1, transactions, prices));
        }
        else{
            profit = max(prices[idx] + solve(idx + 1, 1, transactions - 1, prices), solve(idx + 1, 0, transactions, prices));
        }

        return dp[idx][canBuy][transactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 2, prices);
    }
};

// Bottom-up
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        dp[n][0][0] = dp[n][1][0] = 0;

        for(int idx = n - 1; idx >= 0; idx--){
            for(int buy = 0; buy < 2; buy++){
                for(int transaction = 0; transaction < 3; transaction++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[idx + 1][0][transaction], dp[idx + 1][1][transaction]);
                    } else if(transaction > 0) {
                        profit = max(prices[idx] + dp[idx + 1][1][transaction - 1], dp[idx + 1][0][transaction]);
                    }

                    dp[idx][buy][transaction] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
};
