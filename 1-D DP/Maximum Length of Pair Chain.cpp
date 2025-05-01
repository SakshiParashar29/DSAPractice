// Memoization

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int prev, vector<vector<int>>& pairs)
    {
           if(i >= pairs.size())
              return 0;

           if(prev != -1 && dp[i][prev] != -1)
              return dp[i][prev];

           int take = 0;
           if(prev == -1 || pairs[i][0] > pairs[prev][1])
           {
              take = 1 + solve(i + 1, i, pairs);
           }
           int skip = solve(i + 1, prev, pairs);

           if(prev != -1)
             dp[i][prev] = max(take, skip);
           
           return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, pairs);
    }
};

// Bottom up approach
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
         
        int maxPairs = 1;
        vector<int> dp(pairs.size(), 1);
        for(int i = 0; i < pairs.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(pairs[i][0] > pairs[j][1])
                {
                   dp[i] = max(dp[i], dp[j] + 1);
                   maxPairs = max(maxPairs, dp[i]);
                }
            }
        }
        return maxPairs;
    }
};
