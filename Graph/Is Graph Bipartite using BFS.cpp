// TC : O(V + E) && SC : O(V + E)
class Solution {
public:
   bool Bfs(vector<vector<int>>& graph, int i, vector<int>& color, int curr)
   {
        queue<int> q;
        q.push(i);
        color[i] = 1;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            int curr = color[u];
            for(int& v : graph[u])
            {
                if(color[v] == curr)
                   return false;

                if(color[v] == -1)
                {
                    color[v] = 1 - curr;
                    q.push(v);
                }
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
                if(Bfs(graph, i, color, 1) == false)
                  return false;
            }
        }
        return true;
    }
};
