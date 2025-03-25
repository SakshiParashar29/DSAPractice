class Solution {
public:
    vector<vector<int>> res;
    void solve(int i, int sum, vector<int>& candidates, int target, vector<int>& temp)
    {
        if(sum == target)
        {
            res.push_back(temp);
            return;
        }
        if(sum > target || i >= candidates.size()) 
           return;

        temp.push_back(candidates[i]);
        solve(i, sum + candidates[i], candidates, target, temp);
        temp.pop_back();
        solve(i + 1, sum, candidates, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, 0, candidates, target, temp);
        return res;
    }
};
