s1 - s2 = diff
s1 + s2 = total

=> 2*s1 = total + diff
=> s1 = (total + diff)/2
  using this problem is converted into count number of subsets with given sum
// Recursive
class Solution {
  public:
    int solve(int idx, vector<int>& arr, int target){
        if(idx <= 0){
            return target == 0;
        }
        
        int take = 0;
        if(arr[idx - 1] <= target){
            take = solve(idx - 1, arr, target - arr[idx - 1]);
        }
        int skip = solve(idx - 1, arr, target);
        
        return take + skip;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        
        int total = accumulate(begin(arr), end(arr), 0);
        
        if((total + diff) % 2 != 0) return 0;
        
        int target = (total + diff) / 2;
        
        return solve(n, arr, target);
    }
};

// Memoization

class Solution {
  public:
    int dp[51][301];
    
    int solve(int idx, vector<int>& arr, int target){
        if(idx <= 0){
            return target == 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int take = 0;
        if(arr[idx - 1] <= target){
            take = solve(idx - 1, arr, target - arr[idx - 1]);
        }
        int skip = solve(idx - 1, arr, target);
        
        return dp[idx][target] = take + skip;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        
        int total = accumulate(begin(arr), end(arr), 0);
        
        if((total + diff) % 2 != 0) return 0;
        
        int target = (total + diff) / 2;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(n, arr, target);
    }
};

//Bottom-up
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        int n = arr.size();
        
        if((totalSum + diff) % 2 != 0) return 0;
        
        int target = (totalSum + diff) / 2;
        
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
