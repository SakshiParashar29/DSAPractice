

class Solution {
public:
    int res = 0;
    bool check(vector<int> freq)
    {
        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i] != 0)
               return false;
        }
        return true;
    }
    void solve(int i, vector<vector<int>>& requests, vector<int> freq, int cnt)
    {
        if(i >= requests.size())
        {
            if(check(freq))
            {
                res = max(cnt, res);
            }
            return;
        }
    
        freq[requests[i][0]]--;
        freq[requests[i][1]]++;
        solve(i + 1, requests, freq, cnt + 1);
        freq[requests[i][0]]++;
        freq[requests[i][1]]--;
        solve(i + 1, requests, freq, cnt);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int cnt = 0;
        vector<int> freq(n, 0);
        solve(0, requests, freq, cnt);
        return res;
    }
};
