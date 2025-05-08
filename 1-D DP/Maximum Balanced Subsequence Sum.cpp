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

//Bottom-up Approach
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long res = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            auto it = mp.upper_bound(nums[i] - i);
            long long sum = nums[i];
            if(it != mp.begin())
            {
                it--;
                sum += (*it).second;
            }
            mp[nums[i] - i] = max(mp[nums[i] - i], sum);
            it = mp.upper_bound(nums[i] - i);

            while(it != mp.end() && it->second <= sum)
            {
                mp.erase(it++);
            }
            res = max(res, sum);
        }
        return res;
    }
};
