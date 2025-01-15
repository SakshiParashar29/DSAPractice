// Time Complexity : O(n^2) && SC : O(n + E) and in worst Case if it is complete graph : O(n^2) 
class Solution {
public:
    void Dfs(int u, vector<bool>&visited, unordered_map<int, vector<int>>&adj)
    {
        visited[u] = true;

        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!visited[adj[u][i]])
               Dfs(adj[u][i], visited, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < isConnected.size(); i++) // n^2
        {
            for(int j = 0; j < isConnected[i].size(); j++)
            {
                int u = i + 1;
                int v = j + 1;
                if(isConnected[i][j] == 1)
                   adj[u].push_back(v);
            }
        }
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;
        for(int i = 1; i <= isConnected.size(); i++)
        {
            if(!visited[i])
            {
                provinces++;
                Dfs(i, visited, adj);
            }
        }
        return provinces;
    }
};
