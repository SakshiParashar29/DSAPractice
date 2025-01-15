vector<int> topologicalSort(vector<vector<int>>& adj) {
       int n = adj.size();
       
       vector<bool> visited(n, 0);
       vector<int> inDeg(n, 0);
       queue<int> q;
       for(int u = 0; u < n; u++)
       {
           for(int j = 0; j < adj[u].size(); j++)
           {
                 inDeg[adj[u][j]]++;
           }
       }
       for(int i = 0; i < n; i++)
       {
           if(inDeg[i] == 0)
              q.push(i);
       }
       vector<int> res;
       while(!q.empty())
       {
           int u = q.front();
           q.pop();
           res.push_back(u);
           
           for(int i = 0; i < adj[u].size(); i++)
           {
               inDeg[adj[u][i]]--;
                  
               if(inDeg[adj[u][i]] == 0)
                  q.push(adj[u][i]);
               
           }
       }
       return res;
    }
