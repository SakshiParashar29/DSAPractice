// Approach - 1 - Recursion
class Solution {
public:
    long long solve(int i, int sign, vector<int>& nums)
    {
        if(i >= nums.size())
           return 0;

        long long take = nums[i] * sign + solve(i + 1, sign*(-1), nums);
        long long skip = solve(i + 1, sign, nums);

        return max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        return solve(0, 1, nums);
    }
};

// Aprroach - 2 - Memoization
class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i, int pos, vector<int>& nums)
    {
        if(i >= nums.size())
           return 0;
        if(dp[i][pos] != -1)
           return dp[i][pos];
        long long take = (pos ? nums[i] : -nums[i]) + solve(i + 1, !pos, nums);
        long long skip = solve(i + 1, pos, nums);

        return dp[i][pos] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(nums.size(), vector<long long>(2, -1));
        return solve(0, true, nums);
    }
};

// Bottom-Up approach
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + nums[i-1], dp[i - 1][1]);
        }
        return max(dp[n][1], dp[n][0]);
    }
};
