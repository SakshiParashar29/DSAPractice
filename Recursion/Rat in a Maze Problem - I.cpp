// TC : O(3^n^2). since every index has 4 option to explore and since it can't explore already visited index.
// SC : O(n^2) In worst case we can explore every index when the value at each index in a matrix is one.

class Solution {
  public:
    vector<string> res;
    int n;
    void solve(int i, int j, string path, vector<vector<int>> &mat)
    {
        if(i < 0 || i >= n || j < 0 || j >= n)
          return;
        
        if(i == n - 1 && j == n - 1)
        {
            res.push_back(path);
            return;
        }
        
        if(mat[i][j] == 0)
          return;
        
        mat[i][j] = 0;
        solve(i - 1, j, path + 'U', mat);
        solve(i + 1, j, path + 'D', mat);
        solve(i, j - 1, path + 'L', mat);
        solve(i, j + 1, path + 'R', mat);
        mat[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        n = mat.size();
        solve(0, 0, "", mat);
        return res;
    }
};
