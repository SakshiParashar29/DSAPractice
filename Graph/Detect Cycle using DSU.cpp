int find (int i, vector<int>& parent)
   {
     if(i == parent[i])
       return i;
 
      return parent[i] = find(parent[i], parent);
   }

    void findUnion(int x, int y, vector<int>& parent, vector<int>& rank)
    {
       int x_parent = find(x, parent);
       int y_parent = find(y, parent);

       if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent])
        {
           parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent])
        {
            parent[x_parent] = y_parent;
        }
        else 
        {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1; 
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int> parent(V);
	    vector<int> rank(V);
	    for(int i = 0; i < V; i++)
	    {
	        parent[i] = i;
	        rank[i] = 0;
	    }
	    for(int u = 0; u < V; u++)
	    {
	        for(int &v : adj[u])
	        {
	            if(u < v)
	            {
	                int parent_u = find(u, parent);
	                int parent_v = find(v, parent);
	                
	                if(parent_u == parent_v)
	                   return 1;
	                
	                  findUnion(u, v, parent, rank);
	            }
	        }
	    }
	    return 0;
	}
