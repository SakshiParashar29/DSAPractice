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


// Approach 2 - using idx and with swapping generating all the permutations
class Solution {
public:
    void solve(int idx, vector<vector<int>>& res, vector<int>& nums)
    {
        if(idx >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            solve(idx + 1,res, nums);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, res, nums);
        return res;
    }
};
