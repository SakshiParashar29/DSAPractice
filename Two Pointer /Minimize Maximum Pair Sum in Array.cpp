//Time Complexity : O(N log N) && Space Complexity : O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int maxSum = -1;
        while(i < j)
        {
           maxSum = max(maxSum, nums[i] + nums[j]);
           i++; j--;
        }
        return maxSum;
    }
};
