// on gfg = partitions with given difference
// and it is same as pefect sum problem (count the number of subset with sum k)

// s1 - s2 = diff
// s1 + s2 = totalSum
//---------------------
// 2s1 + 0 = totalSum + diff
// s1 = (totalSum + diff)/2;
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
