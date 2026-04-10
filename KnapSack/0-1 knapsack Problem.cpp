// Approach - 1 (Recursive)
TC : O(2^n)
SC : O(n)

class Solution {
  public:
    int solve(int n, vector<int>& val, vector<int>& wt, int W){
        if(n < 0) return 0;
        
        int take = 0;
        
        if(wt[n] <= W){
            take = val[n] + solve(n - 1, val, wt, W - wt[n]);
        } 
        
        int skip = solve(n - 1, val, wt, W);
        
        return max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        return solve(n - 1, val, wt, W);
    }
};


// Approach - 2 (Top-down Approach)
TC: O(n * W) // dp size [n][W]
SC : O(n * W) + O(n) // n for stack call and n * W for dp array
class Solution {
  public:
    int dp[1004][1004];
    
    int solve(int n, vector<int>& val, vector<int>& wt, int W){
        if(n < 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        int take = 0;
        
        if(wt[n] <= W){
            take = val[n] + solve(n - 1, val, wt, W - wt[n]);
        } 
        
        int skip = solve(n - 1, val, wt, W);
        
        return dp[n][W] = max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        memset(dp, -1, sizeof(dp));
        return solve(n - 1, val, wt, W);
    }
};

// Approach - 3 (BottomUp)
TC : O(n * W)
SC : O(n * W)

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
                int take = 0;
                
                if(wt[i - 1] <= j)
                   take = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                int skip = dp[i - 1][j];
                
                dp[i][j] = max(take, skip);
            }
        }
        return dp[n][W];
    }
};
