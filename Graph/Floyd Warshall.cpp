class Solution {
  public:
    void modify(int via, vector<vector<int>>& dist, int V)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                int d1 = dist[i][via];
                int d2 = dist[via][j];
                
                if(d1 != 100000000 && d2 != 100000000 && (d1 + d2) < dist[i][j])
                {
                    dist[i][j] = d1 + d2;
                }
            }
        }
    }
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        
        // iterating for each vertex so that each can pass via i;
        for(int via = 0; via < V; via++)
        {
            modify(via, dist, V);
        }
    }
};
