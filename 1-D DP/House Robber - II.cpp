//Approach 1 - Recursion || Time Complexity : O(2^N) && Space Complexity : O(N) because of recursive call stack
class Solution {
public:
    int solve(vector<int>& nums, int i, int n)
    {
        if(i >= n) return 0;

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return max(steal, skip);
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int steal = solve(nums, 0, n - 1);
        int skip =  solve(nums, 1, n);
        return max(steal, skip);
    }
};

// Approach 2 - Memoization || Time Complexity : O(N) && Space Complexity : O(N)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n)
    {
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return t[i] = max(steal, skip);
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        memset(t, -1, sizeof(t));
        int take0 = solve(nums, 0, n - 1);
        memset(t, -1, sizeof(t));
        int take_not = solve(nums, 1, n);
        return max(take0, take_not);
    }
};
