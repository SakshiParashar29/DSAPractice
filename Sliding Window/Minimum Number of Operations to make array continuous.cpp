class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        
        int m = nums.size();

        int i = 0, j = 0, cnt = 0;
        while(j < m)
        {
            while(nums[i] + n <= nums[j]) ++i;
            cnt = max(cnt, j - i + 1);

            j++;
        }
        return n - cnt;
    }
};
