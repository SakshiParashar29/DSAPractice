class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, score = 0, res = 0;

        unordered_map<int,int> freq;
        while(j < nums.size())
        {
            freq[nums[j]]++;
            score += nums[j];

            while(freq.size() < (j - i + 1))
            {
                freq[nums[i]]--;
                score -= nums[i];
                if(freq[nums[i]] == 0)
                   freq.erase(nums[i]);
                i++;
            }
            res = max(res, score);
            j++;
        }
        return res;
    }
};
