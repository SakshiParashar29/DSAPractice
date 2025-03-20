class Solution {
public:
    bool solve(string s, string p)
    {
        if(p.length() == 0)
        {
            return s.length() == 0;
        }

        bool firstChar = false;
        if(s.length() > 0 && (s[0] == p[0] || p[0] == '.'))
           firstChar = true;

        if(p[1] == '*')
        {
            bool not_take = solve(s, p.substr(2));
            bool take = firstChar && solve(s.substr(1), p);

            return take || not_take;
        }
        return firstChar && solve(s.substr(1), p.substr(1));
    }
    bool isMatch(string s, string p) {
       return solve(s, p);
    }
};


// Approach 2 - instead of using substr we will use pointer i and j
class Solution {
public:
    bool solve(int i, int j, string& s, string& p)
    {
        if(j == p.length())
        {
            return i == s.length();
        }

        bool firstChar = false;
        if(i < s.length() && (s[i] == p[j] || p[j] == '.'))
           firstChar = true;

        if(p[j + 1] == '*')
        {
            bool not_take = solve(i, j + 2, s, p);
            bool take = firstChar && solve(i + 1, j, s, p);

            return take || not_take;
        }
        return firstChar && solve(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
       return solve(0, 0, s, p);
    }
};

// Memoization
class Solution {
public:
    int t[21][21];
    bool solve(int i, int j, string& s, string& p)
    {
        if(j == p.length())
        {
            return i == s.length();
        }
        if(t[i][j] != -1)
           return t[i][j];
        bool firstChar = false;
        if(i < s.length() && (s[i] == p[j] || p[j] == '.'))
           firstChar = true;

        if(p[j + 1] == '*')
        {
            bool not_take = solve(i, j + 2, s, p);
            bool take = firstChar && solve(i + 1, j, s, p);

            return t[i][j] = take || not_take;
        }
        return t[i][j] = firstChar && solve(i + 1, j + 1, s, p);
    }
    bool isMatch(string s, string p) {
       memset(t, -1, sizeof(t));
       return solve(0, 0, s, p);
    }
};
