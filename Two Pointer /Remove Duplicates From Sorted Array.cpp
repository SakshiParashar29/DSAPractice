 int removeDuplicates(vector<int>& nums) {
        int size = 1;
        int i = 0, j = i + 1;
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                i++;
                swap(nums[i], nums[j]);
                size++;
            }
          j++;
        }
        return size;
    }
