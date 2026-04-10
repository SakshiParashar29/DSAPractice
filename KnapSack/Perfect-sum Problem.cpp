// Recursive

// Input:
// arr[] =
// 28 4 3 27 0 24 26
// target =
// 24
//  important input dry run it for understanding the edgecase of 0s

class Solution {
  public:
    int solve(int n, vector<int>& arr, int target){
        if(n == 0) return (target == 0 ? 1 : 0);
        
        int take = 0;
        
        if(arr[n - 1] <= target){
            take = solve(n - 1, arr, target - arr[n - 1]);
        }
        
        int skip = solve(n - 1, arr, target);
        
        return take + skip;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        return solve(n, arr, target);
    }
};


// Memoization

class Solution {
  public:
    int dp[1004][1004];
    
    int solve(int n, vector<int>& arr, int target){
        if(n == 0) return (target == 0 ? 1 : 0);
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int take = 0;
        
        if(arr[n - 1] <= target){
            take = solve(n - 1, arr, target - arr[n - 1]);
        }
        
        int skip = solve(n - 1, arr, target);
        
        return dp[n][target] = take + skip;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, arr, target);
    }
};


// Bottom-Up approach

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int take = 0;
                if(arr[i - 1] <= j){
                    take = dp[i - 1][j - arr[i - 1]];
                }
                
                int skip = dp[i - 1][j];
                
                dp[i][j] = take + skip;
            }
        }
        return dp[n][target];
    }
};
