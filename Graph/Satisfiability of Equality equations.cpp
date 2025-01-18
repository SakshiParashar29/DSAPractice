class Solution {
public:
   int find(int x, vector<int>& parent)
   {
      if(x == parent[x])
        return x;

      return parent[x] = find(parent[x], parent);
   }
    void UnionFind(int x, int y, vector<int>&parent, vector<int>&rank)
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent) return;

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
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for(int i = 0; i < 26; i++)
        {
            parent[i] = i;
            // rank[i] = 1;
        }
        
        for(string &s : equations)
        {
            if(s[1] == '=')
            {
                UnionFind(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }

        for(string &s : equations)
        {
            if(s[1] == '!')
            {
                char first = s[0];
                char second = s[3];

                int parent_first = find(first - 'a', parent);
                int parent_second = find(second - 'a', parent);

                if(parent_first == parent_second)
                  return false;
            }
        }
        return true;
    }
};
