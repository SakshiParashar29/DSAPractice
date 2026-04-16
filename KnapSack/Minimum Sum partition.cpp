class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        int n = arr.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= totalSum; j++){
                int take = 0;
                if(arr[i - 1] <= j){
                    take = dp[i - 1][j - arr[i - 1]];
                }
                int skip = dp[i - 1][j];
                
                dp[i][j] = take || skip;
            }
        }
        
        int minDiff = INT_MAX;
        for(int i = 0; i <= totalSum/2; i++){
            if(dp[n][i]){
                int diff = totalSum - (2*i);
                minDiff = min(diff, minDiff);
            }
        }
        return minDiff;
    }
};
