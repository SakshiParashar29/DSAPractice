    bool Dfs(vector<vector<int>>& adj,vector<bool>& visited, int v, int p)
    {
        
        visited[v] = true;
        
        for(int i = 0; i < adj[v].size(); i++)
        {
            if(p == adj[v][i])
              continue;
              
            if(visited[adj[v][i]] == true)
              return true;
              
            if(Dfs(adj, visited, adj[v][i], v))
              return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
       vector<bool> visited(n, 0);
     
       for(int i = 0; i < adj.size(); i++)
       {
           if(!visited[i] && Dfs(adj, visited, i, -1))
             return true;
       }
       return false;
    }
};
