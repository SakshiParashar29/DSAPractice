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

// Approach 2 - Using map to store the freq of each element and process it accordingly
// TC : O(n * n!) && SC : O(n! + n)
class Solution {
public:
   void solve(vector<int> temp, vector<int>& nums, unordered_map<int, int>& mp, vector<vector<int>>& res)
  {
    if(temp.size() == nums.size())
    {
        res.push_back(temp);
        return;
    }
    for(auto it :mp)
    {
        if(it.second != 0)
        {
            temp.push_back(it.first);
            mp[it.first]--;
            solve(temp, nums, mp, res);
            mp[it.first]++;
            temp.pop_back();
        }
    }
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>> res;
        vector<int> temp;
        solve(temp, nums, mp, res);
        return res;
    }
};
