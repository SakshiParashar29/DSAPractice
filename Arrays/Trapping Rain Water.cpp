/* Time Complexity : O(N) && Space Complexity : O(N) */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prevGreater(n);
        vector<int> nextGreater(n);

        for(int i = 0; i < height.size(); i++)
        {
            if(i > 0 && height[prevGreater[i - 1]] > height[i])
            {
                prevGreater[i] = prevGreater[i - 1];
            }
            else
            {
                prevGreater[i] = i;
            }
        }
        for(int j = n - 1; j >= 0; j--)
        {
            if(j < n - 1 && height[nextGreater[j + 1]] > height[j])
            {
                nextGreater[j] = nextGreater[j + 1];
            }
            else
            {
                nextGreater[j] = j;
            }
        }
        int trapWaterCnt = 0;
        for(int i = 0; i < n; i++)
        {
            int minBar = min(height[prevGreater[i]], height[nextGreater[i]]);
            trapWaterCnt += minBar - height[i];
        }
        return trapWaterCnt;
    }
};
