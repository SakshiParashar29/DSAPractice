class Solution {
  public:
    bool Dfs(int u, int V, vector<int> adj[], vector<bool>& visited)
    {
        visited[u] = true;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            int neigh = *it;
            if(!visited[neigh])
              Dfs(neigh, V, adj, visited);
        }
    }
    bool isConnected(int V, vector<int> adj[])
    {
        int nonZeroVertix = 0;
        for(int i = 0; i < V; i++)
        {
            if(adj[i].size() > 0)
            {
               nonZeroVertix = i;
               break;
            }
        }
        
        vector<bool> visited(V, false);
        Dfs(nonZeroVertix, V, adj, visited);     
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i] && adj[i].size() != 0)
               return false;
        }
        return true;
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        
        if(isConnected(V, adj) == false)
           return 0;
           
        int oddDegCnt = 0;
        
        for(int i = 0; i < V; i++)
        {
            if(adj[i].size() % 2 != 0)
               oddDegCnt++;
        }
        
        if(oddDegCnt > 2)
           return 0;
        if(oddDegCnt == 2)
           return 1;
           
        return 2;
    }
};
