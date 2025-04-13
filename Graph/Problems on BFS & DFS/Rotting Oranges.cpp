class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> pq;
        int n = grid.size(), m = grid[0].size();
        int freshOranges = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                  pq.push({i, j});
                else if(grid[i][j] == 1)
                   freshOranges++;
            }
        }
        if(freshOranges == 0) return 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = -1;
        while(!pq.empty())
        {
            int size = pq.size();
            time++;

            while(size--)
            {
                int i = pq.front().first;
                int j = pq.front().second;
                pq.pop();

                for(auto& dir : directions)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_i < n && new_j < m && new_j >= 0 && grid[new_i][new_j] == 1)
                    {
                        grid[new_i][new_j] = 2;
                        pq.push({new_i, new_j});
                        freshOranges--;
                    }
                }
            }
        }
        return (freshOranges == 0 ? time : -1);
    }
};
