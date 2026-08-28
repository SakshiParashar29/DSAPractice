// Recursive

class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        if(i >= j) return 0;

        int ans = 0;

        for(int k = i; k < j; k++){
            int left = i - 1 >= 0 ? nums[i - 1] : 1;
            int right = j < nums.size() ? nums[j] : 1;
    
            int temp = solve(i, k, nums) + solve(k + 1, j, nums) + nums[k] * left * right;

            ans = max(temp, ans); 
        }
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n, nums);
    }
};

// Top-Down
class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, vector<int>& nums){
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        for(int k = i; k < j; k++){
            int left = i - 1 >= 0 ? nums[i - 1] : 1;
            int right = j < nums.size() ? nums[j] : 1;
    
            int temp = solve(i, k, nums) + solve(k + 1, j, nums) + nums[k] * left * right;

            ans = max(temp, ans); 
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums);
    }
};
