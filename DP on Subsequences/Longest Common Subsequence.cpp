// TC : O(2^(n+m)), SC: O(n + m)
class Solution {
public:
    int n, m;
    int solve(int n, int m, string& text1, string& text2){
        if(n == 0 || m == 0) return 0;

        int len = 0;

        if(text1[n - 1] == text2[m - 1]){
            len = 1 + solve(n - 1, m - 1, text1, text2);
        } else {
            len = max(solve(n - 1, m, text1, text2), solve(n, m - 1, text1, text2));
        }

        return len;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();

        return solve(n, m, text1, text2);
    }
};

// memoization
// TC: O(n*m)  // because there are n*m states (dp[n][m] and each one is computed once)
// SC: O(n*m) // table dp[n][m];
class Solution {
public:
    int n, m;
    int dp[1001][1001];

    int solve(int n, int m, string& text1, string& text2){
        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        int len = 0;

        if(text1[n - 1] == text2[m - 1]){
            len = 1 + solve(n - 1, m - 1, text1, text2);
        } else {
            len = max(solve(n - 1, m, text1, text2), solve(n, m - 1, text1, text2));
        }

        return dp[n][m] = len;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, m, text1, text2);
    }
};

// Bottom-up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int len = 0;
                if(text1[i - 1] == text2[j - 1]){
                   len = 1 + dp[i - 1][j - 1];
                } else {
                    len = max(dp[i - 1][j], dp[i][j - 1]);
                }
                dp[i][j] = len;
            }
        }
        return dp[n][m];
    }
};

// sc: O(m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(text1[i - 1] == text2[j - 1]){
                    curr[j] = 1 + prev[j - 1];
                }
                else{
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
