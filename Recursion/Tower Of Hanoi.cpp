// TC : O(2^n) && SC : O(n)
class Solution {
  public:
    int solve(int n, int from, int to, int aux)
    {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int count = solve(n - 1, from, to, aux);
        count++;
        count += solve(n - 1, aux, to, from);
        
        return count;
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        return solve(n, from, to, aux);
    }
};
