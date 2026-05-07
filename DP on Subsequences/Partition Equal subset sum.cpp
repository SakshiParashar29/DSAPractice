// recursive

class Solution {
public:
    bool solve(int i, int sum, int half, vector<int>& nums)
    {
        if(i >= nums.size()) return false;

        if(sum == half) return true;

        bool take = solve(i + 1, sum + nums[i], half, nums);
        bool skip = solve(i + 1, sum, half, nums);

        return (take || skip);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % 2 != 0) return false;

        return solve(0, 0, sum/2, nums);
    }
};

// memoization

class Solution {
public:
    int dp[201][10001];
    bool solve(int i, int sum, int half, vector<int>& nums)
    {
        if(sum == half) return true;
        if(i >= nums.size() || sum > half) return false;

        if(dp[i][sum] != -1) return dp[i][sum];


        bool take = solve(i + 1, sum + nums[i], half, nums);
        bool skip = solve(i + 1, sum, half, nums);

        return dp[i][sum] = (take || skip);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        memset(dp, -1, sizeof(dp));
        if(sum % 2 != 0) return false;

        return solve(0, 0, sum/2, nums);
    }
};

// optimisation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if(totalSum % 2 != 0) return false;

        int target = totalSum/2;
        
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int take = 0;
                if(nums[i - 1] <= j){
                    take = dp[i - 1][j - nums[i - 1]];
                }
                int skip = dp[i - 1][j];

                dp[i][j] = take || skip;
            }
        }

        return dp[n][target];
    }
};
