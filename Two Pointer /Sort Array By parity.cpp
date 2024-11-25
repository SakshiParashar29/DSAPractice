// Time Complexity : O(N) && Space Complexity : O(N)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        vector<int> evenNum;
        vector<int> oddNum;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
            {
                evenNum.push_back(nums[i]);
            }
            else
            {
                oddNum.push_back(nums[i]);
            }
        }
        for(int i = 0; i < evenNum.size(); i++)
        {
            res.push_back(evenNum[i]);
        }
        for(int j = 0; j < oddNum.size(); j++)
        {
            res.push_back(oddNum[j]);
        }
        return res;
    }
};

/*class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0;
        while(i < nums.size())
        {
            if(nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};*/
