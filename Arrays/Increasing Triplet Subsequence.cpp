// TC : O(n) && SC : O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int firstSmall = INT_MAX, secondSmall = INT_MAX;

       for(int i = 0; i < nums.size(); i++)
       {
           if(nums[i] <= firstSmall)
             firstSmall = nums[i];
           else if(nums[i] <= secondSmall)
             secondSmall = nums[i];
           else 
              return true;
       }
       return false;
    }
};
