// Approach 1 - Brute Force || TC : O(N) && SC  O(N)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIdx;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == key) keyIdx.push_back(i);
        }
        set<int> s;
        for(int i = 0; i < keyIdx.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(abs(keyIdx[i] - j) <= k) s.insert(j);
            }
        }
        vector<int> res;
        for(int num : s)
        {
            res.push_back(num);
        }
        return res;
    }
};

//Approach 2 : Two - Pointer
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIdx;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == key) keyIdx.push_back(i);
        }
        vector<int> res;
        for(int i = 0, j = 0; i < n && j < keyIdx.size(); i++)
        {
            if(i < keyIdx[j] - k) continue;
            while(j < keyIdx.size() && i > keyIdx[j] + k) ++j;
            if(j < keyIdx.size() && i >= keyIdx[j] - k && i <= keyIdx[j] + k) res.push_back(i);
        }
        return res;
    }
};
