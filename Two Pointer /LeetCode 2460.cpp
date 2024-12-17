// Brute Force || TC : O(N) && SC : O(N)
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] == nums[i + 1])
            {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> res(n); int zeroCnt = 0;
        for(int num : nums)
        {
            if(num == 0) zeroCnt++;
        }
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
            {
                res[idx++] = nums[i];
            }
        }
        for(int i = idx; i < n; i++)
        {
            res[idx++] = 0;
        }
        return res;
    }
};

// Two Pointer || TC : O(N) && SC : O(1)
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] == nums[i + 1])
            {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        int i = 0, j = 0;
        while(i < n && j < n)
        {
             if(nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            if(nums[i] != 0) i++;
            j++;
        } 
        return nums;
    }
};
