// TC : O(n * n!) && SC : O(n!)
class Solution {
public:
    void solve(vector<int> temp, vector<vector<int>>& res, unordered_set<int> s, vector<int>& nums)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]) == s.end())
            {
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                solve(temp, res, s, nums);

                temp.pop_back();
                s.erase(nums[i]);
            }
        }        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> s;
        solve(temp, res, s, nums);
        return res;
    }
};
