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



class Solution {
public:
    int trap(vector<int>& height) {
        int trapWaterCnt = 0;
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = height[0]; right[n - 1] = height[n-1];
        for(int i = 1; i < n; i++)
        {
            left[i] = max(height[i], left[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i], right[i + 1]);
        }
        for(int j = 0; j < n; j++)
        {
            int minheight = min(left[j], right[j]);
            trapWaterCnt += (minheight - height[j]);
        }
        return trapWaterCnt;
    }
};
