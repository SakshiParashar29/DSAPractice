// In unbounded, the concept is same as 0/1. there is item you can take it or skip it. 
// the slightest difference is that you can take already processed item multiple times, which you can't do in 0/1 knapsack. 
// Remember by it your favourate chocolate, if someone give you your favourate chocolate, you can take it multiple times, 
//but when someone give you chocolate which you don't like then you will not take it, doesn't matter how much time they give you!!

// Recursive

class Solution {
  public:
    int solve(int idx, vector<int>& val, vector<int>& wt, int capacity){
        if(idx <= 0) return 0;
        
        int take = 0;
        
        if(wt[idx - 1] <= capacity){
            take = val[idx - 1] + solve(idx, val, wt, capacity - wt[idx - 1]);
        }
        
        int skip = solve(idx - 1, val, wt, capacity);
        
        return max(take, skip);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        return solve(n, val, wt, capacity);
    }
};

// Top-down
class Solution {
  public:
    int dp[1001][1001];
    int solve(int idx, vector<int>& val, vector<int>& wt, int capacity){
        if(idx <= 0) return 0;
        
        if(dp[idx][capacity] != -1) return dp[idx][capacity];
        
        int take = 0;
        
        if(wt[idx - 1] <= capacity){
            take = val[idx - 1] + solve(idx, val, wt, capacity - wt[idx - 1]);
        }
        
        int skip = solve(idx - 1, val, wt, capacity);
        
        return dp[idx][capacity] = max(take, skip);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(n, val, wt, capacity);
    }
};

// Bottom-Up
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        for(int idx = 1; idx <= n; idx++){
            for(int c = 0; c <= capacity; c++){
                int take = 0;
                if(wt[idx - 1] <= c){
                    take = val[idx - 1] + dp[idx][c - wt[idx - 1]];
                }
                
                int skip = dp[idx - 1][c];
                
                dp[idx][c] = max(take, skip);
            }
        }
        
        return dp[n][capacity];
    }
};
