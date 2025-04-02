// TC : O(n^3) && SC : O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        long long temp;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    temp = 1LL*(nums[i] - nums[j])*(nums[k]);
                    if(temp > res)
                       res = temp;   
                }
            }
        }
        return res;
    }
};


// Tc : O(n) && Sc: O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        
       
        for(int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i-1]);
        }
        for(int j = n - 2; j >= 0; j--)
        {
            rightMax[j] = max(rightMax[j+1], nums[j+1]);
        }
        for(int j = 1; j < n; j++)
        {
            res = max(res, 1LL*(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
};
