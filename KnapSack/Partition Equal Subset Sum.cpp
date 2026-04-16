// Brute force
TC : O(2^n)
SC : O(n)
class Solution {
  public:
    bool solve(int n, int target, vector<int>& arr){
        if(n == 0) return (target == 0) ? 1 : 0;
        
        int take = 0;
        if(arr[n - 1] <= target){
            take = solve(n - 1, target - arr[n - 1], arr);
        }
        int skip = solve(n - 1, target, arr);
        
        return take || skip;
    }
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum/2;
        int n = arr.size();
        
        return solve(n, target, arr);
    }
};


// Memoization
class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(int n, int target, vector<int>& arr){
        if(n == 0) return (target == 0) ? 1 : 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int take = 0;
        if(arr[n - 1] <= target){
            take = solve(n - 1, target - arr[n - 1], arr);
        }
        int skip = solve(n - 1, target, arr);
        
        return dp[n][target] = take || skip;
    }
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum/2;
        int n = arr.size();
        dp.resize(n + 1, vector<int>(target + 1, -1));
        
        return solve(n, target, arr);
    }
};

// bottom-up approach
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum/2;
        int n = arr.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int take = 0;
                if(arr[i - 1] <= j){
                    take = dp[i - 1][j - arr[i - 1]];
                }
                int skip = dp[i - 1][j];
                
                dp[i][j] = take || skip;
            }
        }
        
        return dp[n][target];
    }
};
