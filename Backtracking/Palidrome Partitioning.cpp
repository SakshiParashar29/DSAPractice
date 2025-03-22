// TC : O(2^N) && SC : O(n)

class Solution {
public:
    vector<vector<string>> res;
    bool isPali(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end])
              return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int idx, string s, vector<string> curr)
    {
        if(idx == s.size())
        {
            res.push_back(curr);
            return;
        }

        for(int i = idx; i < s.length(); i++)
        {
            if(isPali(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(0, s, curr);
        return res;
    }
};
