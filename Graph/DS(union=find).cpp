// Without Rank and path compression
//https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
int find(int par[], int x) {
     while(x != par[x])
        x = par[x];
        
    return x;
}

void unionSet(int par[], int x, int z) {
    int x_parent = find(par, x);
    int z_parent = find(par, z);
    
    if(x_parent != z_parent)
    {
        par[x_parent] = z_parent;
    }
}
