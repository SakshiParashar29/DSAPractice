// Two pointer approach - TC : O(N) & SC : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices;
        int i = 0, j = numbers.size() - 1;
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                indices.push_back(i + 1);
                indices.push_back(j + 1);
                break;
            }
            if(numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return indices;
    }
};
