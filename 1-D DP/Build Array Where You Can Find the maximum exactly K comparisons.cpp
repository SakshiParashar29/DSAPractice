class Solution {
public:
    int N, M, K;
    int mod = 1e9 + 7;
    int dp[51][51][101];
    int solve(int idx, int searchCost, int maxSofar)
    {
        if(idx == N)
        {
            if(searchCost == K)
               return 1;
            return 0;
        }
        
        if(dp[idx][searchCost][maxSofar] != -1)
           return dp[idx][searchCost][maxSofar];
        int res = 0;

        for(int i = 1; i <= M; i++)
        {
           if(i > maxSofar)
              res = (res + solve(idx + 1, searchCost + 1, i))%mod;
           else
             res = (res + solve(idx + 1, searchCost, maxSofar))%mod;
        }

        return dp[idx][searchCost][maxSofar] = res % mod;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
