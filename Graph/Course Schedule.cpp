// TC : O(V + E) && SC : O(V + E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;

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
        int courses = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            courses++;
            for(int i = 0; i < adj[u].size(); i++)
            {
                inDeg[adj[u][i]]--;
                if(inDeg[adj[u][i]] == 0)
                   q.push(adj[u][i]);
            }
        }
        if(courses == numCourses)
          return true;
        else return false;
    }
};
