class Solution {
public:
    vector<vector<int>> res;
    void solve(int i, int sum, vector<int>& candidates, int& target, vector<int>& temp)
    {
        if(sum == target)
        {
            res.push_back(temp);
            return;
        }
         if(i >= candidates.size())
           return;

       for(int j = i; j < candidates.size(); j++)
        {
            if(j > i && candidates[j] == candidates[j - 1])
               continue;
            if(sum > target) break;
            temp.push_back(candidates[j]);
        solve(j + 1, sum + candidates[j], candidates, target,temp);
        temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, 0,candidates, target, temp);
        return res;
    }
};
