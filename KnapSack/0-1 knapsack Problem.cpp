// Approach - 1 (Recursive)

class Solution {
  public:
    int solve(int n, vector<int>& val, vector<int>& wt, int W){
        if(n < 0) return 0;
        
        int take = 0;
        
        if(wt[n] <= W){
            take = val[n] + solve(n - 1, val, wt, W - wt[n]);
        } 
        
        int skip = solve(n - 1, val, wt, W);
        
        return max(take, skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        return solve(n - 1, val, wt, W);
    }
};
