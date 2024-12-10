//Approach 1 - Recursion || Time Complexity : O(2^N) && Space Complexity : O(N)

class Solution {
public:
   int solve(vector<int>& nums, int i)
   {
       if(i >= nums.size()) return 0;
    
       int steal = nums[i] + solve(nums, i + 2);
       int skip = solve(nums, i + 1);

       return max(steal, skip);
   }
   int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};

//Approach 2 - Memoization || Time Complexity : O(N) && Space Complexity : O(N)

class Solution {
public:
   int solve(vector<int>& nums, int i, vector<int>& dp)
   {
       if(i >= nums.size()) return 0;
       
       if(dp[i] != -1) return dp[i];
       int steal = nums[i] + solve(nums, i + 2, dp);
       int skip = solve(nums, i + 1, dp);

       return dp[i] = max(steal, skip);
   }
   int rob(vector<int>& nums) {
        vector<int> dp(101, -1);
        return solve(nums, 0, dp);
    }
};

// Approach 3 - Bottom Up || Time Complexity : O(N) && Space Complexity : O(N)

class Solution {
public:
   int rob(vector<int>& nums) {
        vector<int> dp(101, -1);
        int n = nums.size();
        dp[0] = 0; dp[1] = nums[0];
        for(int i = 2; i <= n; i++)
        {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            
            dp[i] = max(steal, skip);
        }
        return dp[n];
    }
}; 

// Approach 4 - Constant Space || Time Complexity : O(N) && Space Complexity : O(1)

class Solution {
public:
   int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        int maxSteal = 0;
        int first = 0, second = nums[0];
        for(int i = 2; i <= n; i++)
        {
            int steal = nums[i - 1] + first;
            int skip = second;
            maxSteal = max(steal, skip);
            first = second;
            second = maxSteal;
        }
        return maxSteal;
    }
}; 
