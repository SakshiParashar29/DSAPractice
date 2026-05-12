// Recursive
class Solution {
  public:
    int solve(int len, int& x, int& y, int& z){
        if(len == 0) return 0;
        
        if(len < 0) return -1e9;
        
        int a = solve(len - x, x, y, z);
        int b = solve(len - y, x, y, z);
        int c = solve(len - z, x, y, z);
        
        return 1 + max({a, b, c});
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
       int ans = solve(n, x, y, z);
       
       return ans < 0 ? 0 : ans;
    }
};

// Top-Down

class Solution {
  public:
    vector<int> dp;
    int solve(int len, int& x, int& y, int& z){
        if(len == 0) return 0;
        
        if(len < 0) return -1e9;
        
        if(dp[len] != -1e9) return dp[len];
        
        int a = solve(len - x, x, y, z);
        int b = solve(len - y, x, y, z);
        int c = solve(len - z, x, y, z);
        
        return dp[len] = 1 + max({a, b, c});
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
       dp.resize(n + 1, -1e9);
       int ans = solve(n, x, y, z);
       return ans < 0 ? 0 : ans;
    }
};

// Bottom-up
class Solution {
public:
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1e9);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){

            if(i >= x)
                dp[i] = max(dp[i], dp[i - x] + 1);

            if(i >= y)
                dp[i] = max(dp[i], dp[i - y] + 1);

            if(i >= z)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }

        return dp[n] < 0 ? 0 : dp[n];
    }
};
