// Recursive Approach

class Solution {
  public:
    bool solve(int n, vector<int>& arr, int sum){
        if(sum == 0) return true;
        
        if(n < 0) return false;
        
        
        bool take = false;
        
        if(arr[n - 1] <= sum){
            take = solve(n - 1, arr, sum - arr[n - 1]);
        }
        
        bool skip = solve(n - 1, arr, sum);
        
        return take || skip;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        return solve(n, arr, sum);
    }
};


// Memoization or Top-Down Approach

class Solution {
  public:
    int dp[201][1005];
    bool solve(int n, vector<int>& arr, int sum){
        if(sum == 0) return true;
        
        if(n < 0) return false;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        
        bool take = false;
        
        if(arr[n - 1] <= sum){
            take = solve(n - 1, arr, sum - arr[n - 1]);
        }
        
        bool skip = solve(n - 1, arr, sum);
        
        return dp[n][sum] = take || skip;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, arr, sum);
    }
};


// Bottom-Up
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        
        for(int j = 1; j <= sum; j++){
            dp[0][j] = false;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                bool take = false;
                
                if(arr[i - 1] <= j){
                    take = dp[i - 1][j - arr[i - 1]];
                }
                
                bool skip = dp[i - 1][j];
                
                dp[i][j] = take || skip;
            }
        }
        return dp[n][sum];
    }
};
