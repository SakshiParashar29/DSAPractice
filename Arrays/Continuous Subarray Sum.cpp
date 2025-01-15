/*[23,2,4,6,6], k = 7  - use this test case to understand why you need mp[0] = -1*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
         int sum = 0;
         mp[0] = -1;
         for(int i = 0; i < nums.size(); i++)
         {
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end())
            {
                int size = i - mp[rem];
                if(size >= 2)
                  return true;
            }  
            else
               mp[rem] = i;
         }
         return false;
    }
};
