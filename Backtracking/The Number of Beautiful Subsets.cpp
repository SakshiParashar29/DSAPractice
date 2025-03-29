class Solution {
public: 
    int res = 0;
    void solve(int i, vector<int>& nums, unordered_map<int, int>& mp, int& k)
    {
        if(i >= nums.size())
        {
            res++;
            return;
        }
         
        solve(i + 1, nums, mp, k);

        if(!mp[nums[i] - k] && !mp[nums[i] + k])
        {
            mp[nums[i]]++;
            solve(i + 1, nums, mp, k);
            mp[nums[i]]--;
        }

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        solve(0, nums, mp, k);
        return res - 1;
    }
};
