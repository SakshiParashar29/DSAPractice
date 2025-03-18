// TC : O(2^n * n) and SC : O(2*n) depth of the tree diagram is sc
class Solution
{
    public:
    bool isValid(string str)
    {
        int cnt = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '(')
               cnt++;
            else
              cnt--;
            if(cnt < 0)
               return false;
        }
        return cnt == 0;
    }
    void solve(int n, string& str, vector<string>& res)
    {
        if(str.size() == 2*n)
        {
            if(isValid(str))
               res.push_back(str);
            return;
        }
        
        str.push_back('(');
        solve(n, str, res);
        str.pop_back();
        str.push_back(')');
        solve(n, str, res);
        str.pop_back();
    }
    vector<string> AllParenthesis(int n) 
    {
       string str = "";
       vector<string> res;
       solve(n, str, res);
       return res;
    }
};


//Approach 2 to avoid function isValid
class Solution
{
    public:
    void solve(int open, int close,int n, string& str, vector<string>& res)
    {
        if(str.size() == 2*n)
        {
           res.push_back(str);
            return;
        }
        
        if(open < n)
        {
            open++;
            str.push_back('(');
            solve(open, close, n, str, res);
            open--;
            str.pop_back();
        }
        if(close < open)
        {
            close++;
            str.push_back(')');
            solve(open, close, n, str, res);
            close--;
            str.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
       string str = "";
       vector<string> res;
       solve(0, 0, n, str, res);
       return res;
    }
};
