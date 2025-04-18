class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& time : times)
        {
            int u = time[0];
            int v = time[1];
            int wt = time[2];

            adj[u].push_back({v, wt});
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        visited[k] = true;

        int time = 0;
        while(!pq.empty())
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(wt  > dist[u]) continue;

            for(auto& neigh : adj[u])
            {
                int v = neigh.first;
                int d = neigh.second;

                if(d + wt < dist[v])
                {
                    dist[v] = wt + d;
                    pq.push({d + wt, v});
                    if(!visited[v])
                    {
                        visited[v] = true;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                time = max(dist[i], time);
            }
            else
               return -1;
        }
        return time;
    }
};
