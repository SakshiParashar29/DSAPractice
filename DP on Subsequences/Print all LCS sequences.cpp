// Recursive

class Solution {
  public:
    set<string> res;
    void solve(int n, int m, string temp, string& s1, string& s2, int len){
        if(n == 0 || m == 0){
            if(temp.length() == len){
                string str = temp;
                reverse(begin(str), end(str));
                res.insert(str);
            }
            return;
        }
        
        if(s1[n - 1] == s2[m - 1]){
            temp += s1[n - 1];
            solve(n - 1, m - 1, temp, s1, s2, len);
        } else {
            solve(n - 1, m, temp, s1, s2, len);
            solve(n, m - 1, temp, s1, s2, len);
        }
    }
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int len = dp[n][m];
        
        string temp = "";
        
        solve(n, m, temp, s1, s2, len);
        
        vector<string> ans;
        for(auto& str : res){
            ans.push_back(str);
        }
        
        return ans;
    }
};
