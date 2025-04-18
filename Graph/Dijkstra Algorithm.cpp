// Using Priority Queue
class Solution {
  public:
    void solve(int src, vector<int>& dist, vector<vector<pair<int, int>>>& adj)
    {
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for(auto& neigh : adj[u])
            {
                int v = neigh.first;
                int wt = neigh.second;
                if(dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[u] + wt, v});
                }
            }
        }
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(V, INT_MAX);
        solve(src, dist, adj);
        return dist;
    }
};


// Using Set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        st.insert({0, src});
        
        while(!st.empty())
        {
            auto& it = *st.begin();
            int u = it.second;
            st.erase(it);
            
            for(auto& neigh : adj[u])
            {
                int v = neigh.first;
                int wt = neigh.second;
                
                if(dist[u] + wt < dist[v])
                {
                    if(dist[v] != INT_MAX)
                    {
                        st.erase({dist[v], v});
                    }
                    dist[v] = wt + dist[u];
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};
