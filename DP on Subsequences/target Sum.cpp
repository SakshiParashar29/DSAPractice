// brute force
class Solution {
public:
    int n;
    int solve(int idx, int sum, vector<int>& nums, int target){
        if(idx == n){
           return sum == target;
        }

        int pos = solve(idx + 1, sum + nums[idx], nums, target);
        int neg = solve(idx + 1, sum - nums[idx], nums, target);

        return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        return solve(0, 0, nums, target);
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totalSum = accumulate(begin(nums), end(nums), 0);

        if(totalSum + target < 0) return 0;

        if(totalSum < target || (target + totalSum) % 2 != 0) return false;

        int diff = (target + totalSum)/2;

        vector<vector<int>> dp(n + 1, vector<int>(diff + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= diff; j++){
                int take = 0;
                if(nums[i - 1] <= j){
                    take = dp[i - 1][j - nums[i - 1]];
                }
                int skip = dp[i - 1][j];

                dp[i][j] = take + skip;
            }
        }
        return dp[n][diff];
    }
};
