//Approach 1 - Recursion || Time Complexity : O(2^N) && Space Complexity : O(N) because of recursive call stack
class Solution {
public:
    int solve(vector<int>& nums, int i, int n)
    {
        if(i >= n) return 0;

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return max(steal, skip);
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int steal = solve(nums, 0, n - 1);
        int skip =  solve(nums, 1, n);
        return max(steal, skip);
    }
};

// Approach 2 - Memoization || Time Complexity : O(N) && Space Complexity : O(N)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n)
    {
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return t[i] = max(steal, skip);
    } 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        memset(t, -1, sizeof(t));
        int take0 = solve(nums, 0, n - 1);
        memset(t, -1, sizeof(t));
        int take_not = solve(nums, 1, n);
        return max(take0, take_not);
    }
};

//Approach 3 - Bottom Up || Time Complexity : O(N) && Space Complexity : O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> t(n + 1, -1); t[0] = 0;
        int res1 = 0, res2 = 0;
        for(int i = 1; i <= n - 1; i++)
        {
            int skip = t[i - 1];
            int steal = nums[i - 1] + (i >= 2 ? t[i - 2] : 0);

            t[i] = max(skip, steal);
        }
        res1 = t[n - 1];
        t.clear();
        t[0] = t[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            int skip = t[i - 1];
            int steal = nums[i - 1] + (i >= 2 ? t[i - 2] : 0);

            t[i] = max(skip, steal);
        }
        res2 = t[n];
        return max(res1, res2);
    }
};

// Approach 4 - Constant Space 
class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        
        int prevPrev = 0, prev = 0;
        
        for(int i = l; i<=r; i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;
            
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev     = temp;
        }
        
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];

        if(nums.size() == 2) return max(nums[0], nums[1]);

        int take_first_house = solve(nums, 0, n - 2);

        int skip_first_house = solve(nums, 1, n - 1);

        return max(take_first_house, skip_first_house);

    }
};
