// TC : O(K^n) && SC : O(k + n)

class Solution {
public:
    void solve(int idx,vector<int>& cookies, vector<int>&children, int& res)
    {
        if(idx >= cookies.size())
        {
            int unfairness = *max_element(begin(children), end(children));
            res = min(unfairness, res);
            return;
        }
        
        int cookie = cookies[idx];
        for(int i = 0; i < children.size(); i++)
        {
            children[i] += cookie;
            solve(idx + 1, cookies, children, res);
            children[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        int res = INT_MAX;
        solve(0,cookies, children, res);
        return res;
    }
};
