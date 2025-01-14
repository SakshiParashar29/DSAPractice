bool Bfs(vector<vector<int>>& adj,vector<bool> &visited, int node, int parent)
    {
        queue<pair<int, int>> q;
        q.push({node, -1});
       visited[node] = true;
       while(!q.empty())
       {
           int u = q.front().first;
           int parent = q.front().second;
           q.pop();
           for(int i = 0; i < adj[u].size(); i++)
           {
               if(adj[u][i] == parent)
                 continue;
                
               if(!visited[adj[u][i]])
               {
                   q.push({adj[u][i], u});
                   visited[adj[u][i]] = true;
               }
               else 
                  return true;
           }
       }
       return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
       int n = adj.size();
       vector<bool> visited(n, false);
       for(int i = 0; i < n; i++)
       {
           if(!visited[i] && Bfs(adj, visited, i, -1))
              return true;
       }
       return false;
    }
