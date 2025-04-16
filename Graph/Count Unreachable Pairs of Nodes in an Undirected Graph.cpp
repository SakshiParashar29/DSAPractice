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
        parent[y_parent] = x_parent;
        rank[x_parent]++;
      }
   }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(auto& edge : edges)
        {
            unionSet(edge[0], edge[1], parent, rank);
        }
        unordered_map<int, int> freq;
        for(int i = 0; i < parent.size(); i++)
        {
            freq[find(i, parent)]++;
        }
        int comp = 0;
        for(auto it : freq)
        {
            res += (long long)it.second * (n - it.second - comp);
            comp += it.second;
        }
        return res;
    }
};
