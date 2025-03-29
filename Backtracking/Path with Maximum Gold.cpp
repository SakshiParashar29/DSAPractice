class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        if(i >= n || j >= m || i < 0 || j < 0 ||visited[i][j])
           return 0;

        if(grid[i][j] == 0)
           return 0;
        
        visited[i][j] = true;
        int up = grid[i][j] + solve(i - 1, j, grid, visited);
        int down = grid[i][j] +solve(i + 1, j, grid, visited);
        int left = grid[i][j] +solve(i, j - 1, grid, visited);
        int right = grid[i][j] +solve(i, j + 1, grid, visited);
        visited[i][j] = false;

        return max({up, down, left, right});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] != 0)
                {
                    int gold = solve(i, j, grid, visited);
                    res = max(gold, res);
                }
            }
        }
        return res;
    }
};
