class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
           return -1;
         
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int len = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i == n - 1 && j == m - 1)
                   return len + 1;
                for(auto& dir : directions)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 0){
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 1;
                    }
                }
            }
            len++;
        }
       return -1;
    }
};
