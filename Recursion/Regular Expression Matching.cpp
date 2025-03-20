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
