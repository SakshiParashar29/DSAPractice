// TC : O(V + E) && SC : O(V)
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> res;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            res.push_back(v);
            for(int i = 0; i < adj[v].size(); i++)
            {
                if(!visited[adj[v][i]])
                { 
                    q.push(adj[v][i]);
                    visited[adj[v][i]] = true;
                }
            }
        }
        return res;
    }
