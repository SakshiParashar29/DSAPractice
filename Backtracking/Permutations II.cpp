// Inefficient approach because find will take n! to search for all n! possibilities in worst case so TC : O(n! * n!) & SC : O(n! * n)
class Solution {
public:
    void solve(int idx, vector<vector<int>>& res, vector<int>& nums)
    {
        if(idx >= nums.size())
        {
            auto it = std::find(res.begin(), res.end(), nums);
            if(it == res.end())
              res.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            solve(idx + 1, res, nums);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, res, nums);
        return res;
    }
};
