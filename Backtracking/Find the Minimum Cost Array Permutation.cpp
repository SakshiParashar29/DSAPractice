class Solution {
public:
    int n;
    vector<int> res;
    int minScore = INT_MAX;
   
    void solve(int score, vector<int>& nums, vector<int>& perm, vector<bool>& visited)
    {
        if(score >= minScore)
           return;
        if(perm.size() == nums.size())
        {
            score += abs(perm.back() - nums[perm[0]]);
            if(score < minScore)
            {
                minScore = score;
                res = perm;
            }
            return;
        }

       for(int num = 0; num < n; num++)
       {
           if(!visited[num])
           {
              visited[num] = true;
              perm.push_back(num);
              int s = perm.size();
              solve(score + abs(perm[s - 2] - nums[perm[s - 1]]), nums, perm,visited);
              perm.pop_back();
              visited[num] = false;
           }
       }
    }
    vector<int> findPermutation(vector<int>& nums) {
        vector<int> perm;
        n = nums.size();
        vector<bool> visited(n, false);
        perm.push_back(0);
        visited[0] = true;
        solve(0, nums, perm, visited);
        return res;
    }
};
