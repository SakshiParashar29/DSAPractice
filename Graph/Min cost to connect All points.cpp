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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<int>> vec;

        for(int i = 0; i < V; i++)
        {
            for(int j = i + 1; j < V; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);
                vec.push_back({i, j, dist});
            }
        }
        
        auto comparator = [&](vector<int>& v1, vector<int>& v2)
        {
            return v1[2] < v2[2];
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
