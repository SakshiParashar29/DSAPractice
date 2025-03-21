// TC : O(4^k) && SC : O(k) where k is number of non-obstacle cells

class Solution {
public:
    int m, n, res, totalCell;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void find(int i, int j, vector<vector<int>>& grid, int cnt)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
          return;
        
        if(grid[i][j] == 2)
        {
            if(totalCell == cnt)
               res++;
            return;
        }
        grid[i][j] = -1;
        for(auto& dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            find(new_i, new_j, grid, cnt + 1);
        } 
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int start_i, start_j;
        totalCell = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != -1)
                   totalCell++;
                if(grid[i][j] == 1)
                {
                    start_i = i;
                    start_j = j;
                }
            }
        }
        find(start_i, start_j, grid, 1);
        return res;
    }
};
