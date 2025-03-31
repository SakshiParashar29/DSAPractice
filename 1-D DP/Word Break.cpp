class Solution {
public:
    set<string> st;
    int dp[301];
    bool solve(int idx, string s, vector<string>& wordDict)
    {
        if(idx == s.length())
           return true;
           
           if(dp[idx] != -1)
           {
               return dp[idx];
           }
          for(int l = 1; l <= s.length(); l++)
          {
               string temp = s.substr(idx, l);
              if(st.find(temp) != st.end() && solve(idx + l, s, wordDict))
                  return dp[idx] = true;
          }
          return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        for(string& word : wordDict)
        {
            st.insert(word);
        }
        return solve(0, s, wordDict);
    }
};
