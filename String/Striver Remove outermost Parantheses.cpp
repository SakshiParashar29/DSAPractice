class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;

        string res = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                if(balance > 0)
                   res += s[i];
                balance++;
            }
            else
            {
                balance--;
                if(balance > 0)
                   res += s[i];
            }
        } 
        return res;
    }
};
