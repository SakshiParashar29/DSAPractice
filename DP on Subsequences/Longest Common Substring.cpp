// Recursive
// TC: (2*(n+m)) and SC: O(n+m)
class Solution {
  public:
    int n, m;
    int ans = 0;
    int solve(int n, int m, string& s1, string& s2){
        if(n == 0 || m == 0) return 0;
       
        int len = 0;
        
        if(s1[n - 1] == s2[m - 1]){
            len = 1 + solve(n - 1, m - 1, s1, s2);
            ans = max(ans, len);
        }
        else {
            solve(n - 1, m, s1, s2);
            solve(n, m - 1, s1, s2);
            
            return 0;
        }
        
        return len;
    }
    int longCommSubstr(string& s1, string& s2) {
        n = s1.length(), m = s2.length();
        
        solve(n, m, s1, s2);
        
        return ans;
    }
};

// optimization

class Solution {
public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
};
