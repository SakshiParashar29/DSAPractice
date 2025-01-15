class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp; int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += (i + 1);
            mp[nums[i]]++;
        }
        int currSum = 0;
        for(auto& num : mp)
        {
            if(num.second == 2)
               res.push_back(num.first);
            currSum += num.first;
        }
        res.push_back(sum - currSum);
        return res;
    }
};
