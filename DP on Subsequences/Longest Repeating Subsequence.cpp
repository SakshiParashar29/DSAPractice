class Solution {
  public:
    int n;
    int solve(int n, int m, string& s){
        if(n == 0 | m == 0) return 0;
        
        if(s[n - 1] == s[m - 1] && n != m){
            return 1 + solve(n - 1, m - 1, s);
        }
        
        return max(solve(n - 1, m, s), solve(n, m - 1, s));
    }
    int LongestRepeatingSubsequence(string &s) {
        n = s.length();
        
        return solve(n, n, s);
    }
};

// memoization
class Solution {
  public:
    int n;
    int dp[1001][1001];
    
    int solve(int n, int m, string& s){
        if(n == 0 | m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n - 1] == s[m - 1] && n != m){
            return 1 + solve(n - 1, m - 1, s);
        }
        
        return dp[n][m] = max(solve(n - 1, m, s), solve(n, m - 1, s));
    }
    int LongestRepeatingSubsequence(string &s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(n, n, s);
    }
};


// Bottom-up
class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s[j - 1] && i != j){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][n];
    }
};
