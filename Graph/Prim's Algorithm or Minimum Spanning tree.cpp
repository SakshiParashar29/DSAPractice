class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        typedef pair<int, int> P;
        vector<bool> visited(V, false);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        
        int res = 0;
        
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(visited[node])
               continue;
               
            res += wt;
            visited[node] = true;
            
            for(auto& neigh : adj[node])
            {
                int wt = neigh[1];
                int u = neigh[0];
                
                pq.push({wt, u});
            }
        }
        return res;
    }
};
