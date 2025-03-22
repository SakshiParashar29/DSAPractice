// TC : O(2^n) && SC : O(n * 2^n)

class Solution {
public:
   vector<vector<int>> res;
    void solve(int i, vector<int>& nums, vector<int>& temp)
    {

        if(temp.size() >= 2)
            res.push_back(temp); 

        unordered_set<int> st;

        for(int idx = i; idx < nums.size(); idx++)
        {
            if((temp.empty() || nums[idx] >= temp.back()) && (st.find(nums[idx]) == st.end())) 
           {
              temp.push_back(nums[idx]); 
              solve(idx + 1, nums, temp);
              temp.pop_back();
              st.insert(nums[idx]);
           }
        
        }  
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return res;
    }
};
