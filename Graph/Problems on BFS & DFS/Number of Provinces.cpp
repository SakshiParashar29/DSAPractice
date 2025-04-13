class Solution {
public:
    void Dfs(int u, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[u] = true;

        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!visited[adj[u][i]])
               Dfs(adj[u][i], adj, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1);

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(isConnected[i-1][j-1] == 1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        int provinceCnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                provinceCnt++;
                Dfs(i, adj, visited);
            }
        }
        return provinceCnt;
    }
};
