class Solution {
  public:
    void Dfs(int node, vector<bool>& visited, vector<vector<int>>& adj2)
    {
        visited[node] = true;
        
        for(auto& v : adj2[node])
        {
            if(!visited[v])
               Dfs(v, visited, adj2);
        }
    }
    void topologicalSort(int u, stack<int>& s, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[u] = true;
        
        for(auto& v : adj[u])
        {
            if(!visited[v])
              topologicalSort(v, s, adj, visited);
        }
        
        s.push(u);
    }
    int kosaraju(vector<vector<int>> &adj) {
        stack<int> s;
        int V = adj.size();
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
               topologicalSort(i, s, adj, visited);
        }
           
           
        vector<vector<int>> adj2(V);
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
            {
                int u = adj[i][j];
     
                adj2[u].push_back(i);
            }
        }
        
        fill(begin(visited), end(visited), false);
        int components = 0;
        while(!s.empty())
        {
            int u = s.top();
            s.pop();
            if(!visited[u])
            {
                components++;
                Dfs(u, visited, adj2);
            }
        }
        return components;
    }
};
