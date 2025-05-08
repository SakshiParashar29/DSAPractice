// Memoization
class Solution {
public:
    unordered_map<string, int> mp;
    long long solve(int currIdx, int prevIdx, vector<int>& nums)
    {
        if(currIdx >= nums.size())
           return 0;
        string key = to_string(prevIdx) + "_" + to_string(currIdx);
        if(mp.find(key) != mp.end())
           return mp[key];
        long long take = INT_MIN, skip = INT_MIN;
        if(prevIdx == -1 || (nums[currIdx] - nums[prevIdx]) >= (currIdx - prevIdx))
        {
            take = nums[currIdx] + solve(currIdx + 1, currIdx, nums);
        }
        skip = solve(currIdx + 1, prevIdx, nums);

        return mp[key] = max(take, skip);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxNum = *max_element(begin(nums), end(nums));
        if(maxNum < 0)
           return maxNum;
        return solve(0, -1, nums);
    }
};
