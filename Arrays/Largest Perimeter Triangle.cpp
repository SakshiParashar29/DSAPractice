// TC : O(n logn) && SC : O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size(), maxPerimeter = 0;
        sort(nums.begin(), nums.end());
        for(int i = n - 3; i >= 0; i--)
        {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];
            if(a + b > c)
            {
                maxPerimeter = max(maxPerimeter, (a + b + c));
            }
        }
        return maxPerimeter;
    }
};
