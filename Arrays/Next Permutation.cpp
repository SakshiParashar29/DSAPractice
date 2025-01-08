// TC : O(n) && SC : O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1, n = nums.size();
        for(int j = n - 1; j > 0; j--)
        {
            if(nums[j] > nums[j - 1])
            {
                index = j - 1;
                break;
            }
        }
        if(index != -1)
        {
            int nextGreater = index;
            for(int j = n - 1; j >= index + 1; j--)
            {
                if(nums[j] > nums[index])
                {
                    nextGreater = j;
                    break;
                }
            }
            swap(nums[nextGreater], nums[index]);
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};
