class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        if(prerequisites.size() == 0) {
            for(int i = numCourses - 1; i >= 0; i--)
               res.push_back(i);

           return res;
        }

        unordered_map<int, vector<int>> adj;
        vector<int> inDeg(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(inDeg[i] == 0)
              q.push(i);
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int i = 0; i < adj[u].size(); i++)
            {
                inDeg[adj[u][i]]--;
                if(inDeg[adj[u][i]] == 0)
                   q.push(adj[u][i]);
            }
        }
        if(res.size() == numCourses)
           return res;
        else
           return {};
    }
};
