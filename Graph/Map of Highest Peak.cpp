class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(isWater[i][j] == 1)
                {
                    q.push({i, j});
                    isWater[i][j] = 0;
                    visited[i][j] = true;
                } 
            }
        }

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto& dir : directions)
                {
                    int r_ = r + dir[0];
                    int c_ = c + dir[1];

                    if(r_ >= 0 && c_ >= 0 && r_ < n && c_ < m && visited[r_][c_] == false)
                    {
                        isWater[r_][c_] = 1 + isWater[r][c];
                        visited[r_][c_] = true;
                        q.push({r_, c_});
                    }
                }
            }
        }
        return isWater;
    }
};
