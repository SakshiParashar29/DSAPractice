// Time Complexity: O(V + E) && SC : O(V + E)
void Dfs(vector<vector<int>>& adj, vector<bool>&visited, int u, stack<int>&s)
    {
        visited[u] = true;
        
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!visited[adj[u][i]])
               Dfs(adj, visited, adj[u][i], s);
        }
        s.push(u);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
       int n = adj.size();
       
       vector<bool> visited(n, 0);
       stack<int> s;
       vector<int> res;
       for(int i = 0; i < n; i++)
       {
           if(!visited[i])
             Dfs(adj, visited, i, s);
       }
       while(!s.empty())
       {
           res.push_back(s.top());
           s.pop();
        }
       return res;
    }
