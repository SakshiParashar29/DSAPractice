 vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx = 0, negIdx = 1;
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) 
            {
                res[posIdx] = nums[i];
                posIdx += 2;
            }
            if(nums[i] < 0)
            {
                res[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        return res;
    }
