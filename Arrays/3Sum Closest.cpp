/* Brute Force - TC : O(N^3) && SC : O(1)*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = 100000;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    int closest = nums[i] + nums[j] + nums[k];
                    if(abs(closestSum - target) > (abs(closest - target)))
                    {
                        closestSum = closest;
                    }
                }
            }
        }
        return closestSum;
    }
};

/* Two Pointer Approach & sort the array - TC : O(N^2) && SC : O(1)
  whenever we get questions like this and we don't have to return the index then sort the array and use two pointer
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = 100000;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(closestSum - target))
                {
                    closestSum = sum;
                }

                if(sum < target)
                {
                    j++;
                }
                else k--;
            }
        }
        return closestSum;
    }
};
