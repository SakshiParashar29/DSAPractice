/* TC : O(N^2) && SC: O(1) */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int row = matrix.size(), col = matrix[0].size();

         for(int i = 0; i < row; i++)
         {
            for(int j = i; j < col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
         }

         for(int i = 0; i < row; i++)
         {
            int low = 0;
            int high = row - 1;
            while(low <= high)
            {
                swap(matrix[i][low], matrix[i][high]);
                low++;
                high--;
            }
         }
    }
};
