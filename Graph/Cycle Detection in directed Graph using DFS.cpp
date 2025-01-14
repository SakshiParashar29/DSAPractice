// Dry Run this example : 0-->1<--2 for checking why undirected logic won't work here. for cycle detection in directed graph inrecursion vector is needed.
bool Dfs(vector<vector<int>> adj, vector<bool>&visited,vector<bool>&inRecursion, int u)
    {
        visited[u] = true;
        inRecursion[u] = true;
        
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(visited[adj[u][i]] == false && Dfs(adj, visited, inRecursion, adj[u][i]))
               return true;
            else if(inRecursion[adj[u][i]] == true)
               return true;
        }
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
         
        for(int i = 0; i < V; i++)
        {
            if(!visited[i] && Dfs(adj, visited, inRecursion, i))
               return true;
        }
        return false;
    }
