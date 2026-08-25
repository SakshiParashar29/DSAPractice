class Solution {
public:
    int solve(int i, int j, int count, vector<int>& cuts, int& size){
        if(i >= j) return 0;

        int ans = INT_MAX;
        
        for(int k = 0; k < size; k++){
            int c = cuts[k];

            if(c > i && c < j){
                int temp = (j - i) + solve(i, c, count + 1, cuts, size) + solve(c, j, count + 1, cuts, size);
                ans = min(temp, ans);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();

        return solve(0, n, 0, cuts, size);
    }
};


class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& cuts){
        if(i + 1 >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        
        for(int k = i + 1; k < j; k++){
            int temp = (cuts[j] - cuts[i]) + solve(i, k, cuts) + solve(k, j, cuts);
            ans = min(temp, ans);
        }
        return dp[i][j] = ans == INT_MAX ? 0 : ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        int size = cuts.size();

        sort(begin(cuts), end(cuts));
        dp.resize(size + 1, vector<int>(size + 1, -1));
        
        return solve(0, size - 1, cuts);
    }
};
