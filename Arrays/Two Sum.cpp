//Time complexity - O(N)
//Space complexity - O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp;
       for(int i = 0; i < nums.size(); i++)
       {
          int x = target - nums[i];
          if(mp.find(x) != mp.end())
          {
             return {i, mp[x]};
          }
          mp[nums[i]] = i;
       }
       return {};
    }
};


/*Brute force : Time Complexity : O(N^2) && Space Complexity = O(1)
    Sorting with two pointer : Time Complexity : O(NlogN) && Space Complexity = O(1)
    */
