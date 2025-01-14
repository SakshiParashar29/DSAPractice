// TC : O(V + E) && SC : O(V) 
void Dfs(vector<vector<int>>& adj, int v, vector<bool>& visited, vector<int>& res)
    {
        if(visited[v] == true)
          return;
        
        visited[v] = true;
        res.push_back(v);
        for(int i = 0; i < adj[v].size(); i++)
        {
            if(!visited[adj[v][i]])
               Dfs(adj, adj[v][i], visited, res);
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        
        vector<int> res;
        Dfs(adj, 0, visited, res);
        return res;
    }
