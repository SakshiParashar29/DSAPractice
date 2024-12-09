/* Time Complexity : O(2^n) && Space Complexity : O(n)*/
//Recursive code
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};


//Approach 2 - Memoization 
//Time complexity : O(n) && space complexity : O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp)
    {
        if(dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0; dp[1] = 1;
        return solve(n, dp);
    }
};

//Approach 3 - Botton up approach
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0; dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//Approach 4 - Constant Space
//Time complexity : O(n) && space complexity : O(1)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int t1 = 0, t2 = 1, t3;
        for(int i = 2; i <= n; i++)
        {
            t3 = t1 + t2;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};
