bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> inDeg(V, 0);
        queue<int> q;

        // calculate the indegrees of all node
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
            {
                inDeg[adj[i][j]]++;
            }
        }

        // push the node which has 0 inDegree in queue
        for(int i = 0; i < V; i++)
        {
            if(inDeg[i] == 0)
               q.push(i);
        }
        int Cnt = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            Cnt++;
            
            for(int i = 0; i < adj[u].size(); i++)
            {
                inDeg[adj[u][i]]--;
                
                if(inDeg[adj[u][i]] == 0)
                   q.push(adj[u][i]);
            }
        }
        if(Cnt == V)
           return false; // if visit all nodes means there is no cycle else return true;
        else
           return true; 
    }
