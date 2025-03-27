class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,int sum, int& k, int& n, vector<int>& temp)
    {
        if(temp.size() == k && sum == n)
        {
            res.push_back(temp);
            return;
        }
        if(temp.size() >= k || i > 9 || sum > n)
           return;
        
        temp.push_back(i);
        solve(i + 1, sum + i, k, n, temp);
        temp.pop_back();
        solve(i + 1, sum, k, n, temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1, 0,k, n, temp);
        return res;
    }
};
