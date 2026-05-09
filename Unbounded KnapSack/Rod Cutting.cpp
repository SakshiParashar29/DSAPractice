// Recursive

class Solution {
  public:
    int solve(int len, vector<int>& price, int n){
        if(n <= 0 || len <= 0) return 0;
        
        int take = 0;
        if(len <= n){
            take = price[len - 1] + solve(len, price, n - len);
        } 
        
        int skip = solve(len - 1, price, n);
        
        return max(take, skip);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        return solve(n, price, n);
    }
};

// Top-Down

class Solution {
  public:
    int dp[1001][1001];
    int solve(int len, vector<int>& price, int n){
        if(n <= 0 || len <= 0) return 0;
        
        if(dp[len][n] != -1) return dp[len][n];
        
        int take = 0;
        if(len <= n){
            take = price[len - 1] + solve(len, price, n - len);
        } 
        
        int skip = solve(len - 1, price, n);
        
        return dp[len][n] = max(take, skip);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(n, price, n);
    }
};

// Bottom-Up

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int len = 1; len <= n; len++){
            for(int j = 0; j <= n; j++){
                int take = 0;
                if(len <= j){
                    take = price[len - 1] + dp[len][j - len];
                }
                
                int skip = dp[len - 1][j];
                
                dp[len][j] = max(take, skip);
            }
        }
        
        return dp[n][n];
    }
};
