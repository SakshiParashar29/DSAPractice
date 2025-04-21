class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n == 1 && m == 1)
           return 0;
        typedef pair<int, pair<int, int>> P;
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
         
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty())
        {
            int diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(auto& dir : directions)
            {
                int _i = i + dir[0];
                int _j = j + dir[1];

                if(_i >= 0 && _i < n && _j >= 0 && _j < m)
                {
                    int absDiff = abs(heights[i][j] - heights[_i][_j]);
                    int maxDiff = max(absDiff, diff);
                    if(maxDiff < dist[_i][_j])
                    {
                        dist[_i][_j] = maxDiff;
                        pq.push({maxDiff, {_i, _j}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
