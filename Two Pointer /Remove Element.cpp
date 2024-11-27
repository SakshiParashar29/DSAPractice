int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); int occ = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == val)
            {
                occ++;
                if(nums[i + 1] != nums[i])
                {
                    swap(nums[i + 1], nums[i]);
                }
            }
        }
        return n - occ;
    }
