// Brute force
TC : O(2^n)
SC : O(n)
class Solution {
  public:
    bool solve(int n, int target, vector<int>& arr){
        if(n == 0) return (target == 0) ? 1 : 0;
        
        int take = 0;
        if(arr[n - 1] <= target){
            take = solve(n - 1, target - arr[n - 1], arr);
        }
        int skip = solve(n - 1, target, arr);
        
        return take || skip;
    }
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(begin(arr), end(arr), 0);
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum/2;
        int n = arr.size();
        
        return solve(n, target, arr);
    }
};
