class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                int j = mp[nums[i]];
                if(abs(i - j) <= k)
                   return true;
            }  
            mp[nums[i]] = i;
        }
        return false;
    }
};
