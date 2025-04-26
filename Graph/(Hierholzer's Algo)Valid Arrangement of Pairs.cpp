// Hierholzer's Algorithm or euler in directed graph
class Solution {
public:
    void Dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& path)
    {
        while(!adj[u].empty())
        {
            int v = adj[u].back();
            adj[u].pop_back();
            Dfs(v, adj, path);
        }
        path.push_back(u);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int V = pairs.size();

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inDeg, outDeg;

        for(auto& pair : pairs)
        {
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            inDeg[v]++;
            outDeg[u]++;
        }
        int startNode = pairs[0][0];
        for(auto& it : adj)
        {
            int node = it.first;
            if((outDeg[node] - inDeg[node]) == 1)
            {
                startNode = node;
                break;
            }
        }
        
        vector<int> path;
        Dfs(startNode, adj, path);
        reverse(path.begin(), path.end());

        vector<vector<int>> res;
        for(int i = 0; i < path.size() - 1; i++)
        {
            res.push_back({path[i], path[i + 1]});
        }
        return res;
    }
};
