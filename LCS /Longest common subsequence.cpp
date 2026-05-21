// Recursive

class Solution {
public:
    int n, m;
    int solve(int i, int j, string& text1, string& text2){
        if(i >= n || j >= m) return 0;

        int take = 0;

        if(text1[i] == text2[j]){
            take = 1 + solve(i + 1, j + 1, text1, text2);
        }

        int skip = max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));

        return max(take, skip);
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();

        return solve(0, 0, text1, text2);
    }
};


// Top - Down
class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int solve(int i, int j, string& text1, string& text2){
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;

        if(text1[i] == text2[j]){
            take = 1 + solve(i + 1, j + 1, text1, text2);
        }

        int skip = max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));

        return dp[i][j] = max(take, skip);
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();

        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, text1, text2);
    }
};

// bottom-up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int take = 0, skip = 0;

                if(text1[i] == text2[j]){
                   take = 1 + dp[i + 1][j + 1];
                } else {
                    skip = max(dp[i][j + 1], dp[i + 1][j]);
                }

                dp[i][j] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};
