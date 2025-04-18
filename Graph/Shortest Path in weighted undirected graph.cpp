class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> parent(n + 1);
        vector<int> dist(n+1, INT_MAX);
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto& neigh : adj[u])
            {
                int v = neigh.first;
                int wt = neigh.second;
                
                if(d + wt < dist[v])
                {
                    dist[v] = d + wt;
                    pq.push({d + wt, v});
                    parent[v] = u;
                }
            }
        }
        vector<int> res;
        int node = n;
        if(dist[node] == INT_MAX)
           return {-1};
        
        while(parent[node] != node)
        {
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(1);
        res.push_back(dist[n]);
        reverse(begin(res), end(res));
        
        return res;
    }
};
