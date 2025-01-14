// TC : O(n) && SC : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(i > 0) 
               leftSum[i] = leftSum[i - 1] + nums[i];
            else 
               leftSum[i] = nums[i];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(i < n - 1)
               rightSum[i] = rightSum[i + 1] + nums[i];
            else
               rightSum[i] = nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(leftSum[i] == rightSum[i])
               return i;
        }
        return -1;
    }
};
