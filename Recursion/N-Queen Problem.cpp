// TC : O(N!) && SC : O(N)
class Solution {
  public:
    vector<vector<int>> res;
    bool isSafe(int r, int c, vector<vector<int>>& mat)
    {
        int n = mat.size();
        
        for(int i = 0; i < r; i++)
        {
            if(mat[i][c] == 1)
               return false;
        }
        
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        {
            if(mat[i][j] == 1)
               return false;
        }
        
        for(int i = r, j = c; i >= 0 && j < n; i--, j++)
        {
            if(mat[i][j] == 1)
               return false;
        }
        return true;
    }
    void solve(vector<vector<int>>& mat, int row, int n, vector<int> temp)
    {
        if(temp.size() == n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int col = 0; col < n; col++)
        {
            if(isSafe(row, col, mat))
            {
                mat[row][col] = 1;
                temp.push_back(col + 1);
                solve(mat, (row + 1), n,temp);
                mat[row][col] = -1;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> mat(n, vector<int>(n, -1));
        vector<int> temp;
        solve(mat, 0, n, temp);
        return res;
    }
};
