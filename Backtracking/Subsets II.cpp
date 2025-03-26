// TC : O(n log n + 2^n) && SC : O(n)
class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx, vector<int>& nums, vector<int>& temp)
    {
        if(idx >= nums.size())
        {
            res.push_back(temp);
            return;
        }

       
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp);
        temp.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx + 1])
             idx++;
        solve(idx + 1, nums, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, nums, temp);
        return res;
    }
};
