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

// Using BFS
class Solution {
public:
    void Bfs(int u, vector<vector<int>>& adj, vector<bool>& visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for(int i = 0; i < adj[v].size(); i++)
            {
                if(!visited[adj[v][i]])
                {
                    q.push(adj[v][i]);
                    visited[adj[v][i]] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provincesCnt = 0;
        int V = isConnected.size();
        vector<vector<int>> adj(V + 1);
        for(int i = 1; i <= V; i++)
        {
            for(int j = 1; j <= V; j++)
            {
                if(isConnected[i - 1][j - 1] == 1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V+1, false);
        for(int i = 1; i <= V; i++)
        {
            if(!visited[i])
            {
               Bfs(i, adj, visited);
               provincesCnt++;
            }  
        }
        return provincesCnt;
    }
};
