// Brute Force Approach
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot){
        vector<int> smaller;
        vector<int> equal;
        vector<int> greater;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot)
            {
                smaller.push_back(nums[i]);
            }
            else if(nums[i] == pivot)
            {
                equal.push_back(nums[i]);
            }
            else
            {
                greater.push_back(nums[i]);
            }
        }

        vector<int> res;
        for(int i = 0; i < smaller.size(); i++)
        {
            res.push_back(smaller[i]);
        }
        for(int i = 0; i < equal.size(); i++)
        {
            res.push_back(equal[i]);
        }
        for(int i = 0; i < greater.size(); i++)
        {
            res.push_back(greater[i]);
        }
        return res;
    }
};

// Approach -2 Two pass placement
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot){
        vector<int> res(nums.size());

        int smallerCnt = 0, equalCnt = 0;
        for(int num : nums)
        {
            if(num < pivot) smallerCnt++;
            else if(num == pivot) equalCnt++;
        }

        int smallerIdx = 0, equalIdx = smallerCnt;
        int greaterIdx = smallerCnt + equalCnt;

        for(int num : nums)
        {
            if(num < pivot)
            {
               res[smallerIdx++] = num;
            }
            else if(num == pivot)
            {
                res[equalIdx++] = num;
            }
            else
            {
                res[greaterIdx++] = num;
            }
        }
        return res;
    }
};
