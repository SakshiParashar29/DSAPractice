// TC : O(V + E) && SC : O(V + E)
class Solution {
public:
   bool Dfs(vector<vector<int>>& graph, int currNode, vector<int>&color, int currClr)
   {
            color[currNode] = currClr;

            for(int& v : graph[currNode])
            {
                if(color[v] == currClr)
                  return false;
                
                if(color[v] == -1)
                {
                    int colorV = 1 - currClr;
                    if(Dfs(graph, v, color, colorV) == false)
                      return false;
                }
            }
        return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();   
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(Dfs(graph, i, color, 1) == false)
                  return false;
            }
        }
        return true;
    }
};
