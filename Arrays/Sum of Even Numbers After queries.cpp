// TC : O(n + m) && SC : O(n + m)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0) 
            {  
                 sum += nums[i];
                 mp[i] = i;
            }
        }
        for(int i = 0; i < queries.size(); i++)
        {
            int index = queries[i][1];
            int value = queries[i][0];
            int temp = value + nums[index];
            if(mp.find(index) != mp.end())
            {
               sum -= nums[index];
               mp.erase(index);
            }
            if(abs(temp) % 2 == 0)
            {
                sum += temp;
                mp[index] = index;
            }
            res.push_back(sum);
            nums[index] = temp;
        }
        return res;
    }
};
