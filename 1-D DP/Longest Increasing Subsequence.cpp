// Approach - 1 (Recursion)
class Solution {
public:
    int maxLen = INT_MIN;
    void solve(int idx, int prev, int len, vector<int>& nums)
    {
         if(idx >= nums.size())
        {
            maxLen = max(len, maxLen);
            return;
        }

        if(nums[idx] > prev)
        {
            solve(idx + 1, nums[idx], len + 1, nums);
        }
        solve(idx + 1, prev, len, nums);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = INT_MIN;
        solve(0, prev, 0, nums);
        return maxLen;
    }
};

// Memoization
class Solution {
public:
    int take, skip;
    int dp[2501][2501];
    int solve(int i, int prev, vector<int>& nums)
    {
        if(i >= nums.size())
           return 0;

        if(prev != -1 && dp[i][prev] != -1)
           return dp[i][prev];

        int take = 0;
        if(prev == -1 || nums[prev] < nums[i])
           take = 1 + solve(i + 1, i, nums);

        int skip = solve(i + 1, prev, nums);

        if(prev != -1)
           dp[i][prev] = max(take, skip);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};

// Bottom-up Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLIS = 1;
        vector<int> dp(n, 1);

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(nums[i] > nums[j])
                {
                   dp[i] = max(dp[i], dp[j] + 1);  
                   maxLIS = max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
};
