class Solution {
  public:
    int find(int x, vector<int>& parent)
    {
        if(x != parent[x])
           parent[x] = find(parent[x], parent);
           
        return parent[x];
    }
    void unionSet(int x, int y, vector<int>& parent, vector<int>& rank)
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        
        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> vec;
        
        for(int u = 0; u < V; u++)
        {
            for(auto& edge : adj[u])
            {
                int v = edge[0];
                int wt = edge[1];
                
                vec.push_back({u, v, wt});
            }
        }
        
        auto comparator=[&](vector<int>& vec1, vector<int>& vec2){
            return vec1[2] < vec2[2];
        };

        sort(begin(vec), end(vec), comparator);
        
        int sum = 0;
        
        vector<int> parent(V), rank(V, 0);
        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        for(auto& temp : vec)
        {
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u, parent);
            int parent_v = find(v, parent);
            
            if(parent_u != parent_v)
            {
                unionSet(parent_u, parent_v, parent, rank);
                sum += wt;
            }
        }
        return sum;
    }
};
