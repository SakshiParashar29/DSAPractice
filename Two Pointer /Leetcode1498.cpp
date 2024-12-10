// Number of Subsequences that satisfy the given sum condition.
// Time Complexity : O(N log N) && Space Complexity : O(N)

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int M = 1e9 + 7;
        int n = nums.size();
        int l = 0, r = n - 1, res = 0;
        vector<int> power(n);
        power[0] = 1;

        for(int i = 1; i < n; i++)
        {
            power[i] = ((power[i - 1] * 2) % M);
        }
        while(l <= r)
        {
            if(nums[l] + nums[r] > target)
            {
                r--;
            }
            else
            {
                int diff = r - l;
                res = (res % M + power[diff]) % M;
                l++;
            }
        }
        return res;
    }
};
