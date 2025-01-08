/* TC : O(n) && SC : O(1) */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;

        int maxArea = 0;
        while(left < right)
        {
            int w = right - left;
            int h = min(height[left], height[right]);

            int area = w * h;
            maxArea = max(maxArea, area);
            if(height[left] > height[right])
               right--;
            else left++;
        }
        return maxArea;
    }
};
