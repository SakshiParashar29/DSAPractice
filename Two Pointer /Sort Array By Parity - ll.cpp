
vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < n)
        {
            while(i < n && nums[i] % 2 == 0) i += 2;
            if(i == n) break;

            while(j >= 0 && nums[j] % 2 != 0) j -= 2;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
