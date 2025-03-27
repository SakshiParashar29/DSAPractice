// using bt
class Solution {
public:
int cnt = 0;
    void solve(int idx, int sum, vector<int>& nums, int& target)
    {
        if(sum == target)
        {
            cnt++;
            return;
        }
        if(idx >= nums.size() || sum > target)
           return;
        solve(0, sum + nums[idx], nums, target);
        solve(idx + 1, sum, nums, target);
    }
    int combinationSum4(vector<int>& nums, int target) {
        solve(0, 0, nums, target);
        return cnt;
    }
};
// 2nd Approach - Using DP beacause BT gives TLE
class Solution {
public:
    int dp[201][1001];
    int solve(int idx, vector<int>& nums, int target)
    {
        if(target == 0)
           return 1;
        if(idx >= nums.size() || target < 0)
           return 0;
         
        if(dp[idx][target] != -1)
           return dp[idx][target];
        int take_idx = solve(0, nums, target - nums[idx]);
        int not_take = solve(idx+1, nums, target);

        return dp[idx][target] = take_idx + not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, target);
    }
};
