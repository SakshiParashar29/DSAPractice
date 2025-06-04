class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, i = 0, j = 0;
        int cnt = 0;

        while(j < nums.size())
        {
           cnt += nums[j] == 0;
           while(cnt > 1) 
             cnt -= nums[i++] == 0;

           res = max(res, j - i);
           j++;
        }
        return res;
    }
};
