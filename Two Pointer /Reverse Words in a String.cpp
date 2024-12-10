//Approach 1 - using tokenizer
class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
       string token = "";
       string res = "";
       while(ss >> token)
       {
          res = token + " " + res;
       }
       return res.substr(0, res.length() - 1);
    }
};

//Approach 2 - Two pointers
//Time complexity : O(n) && space complexity : O(1);
string reverseWords(string s) {
       reverse(s.begin(), s.end());
       int l = 0, r = 0, i = 0;
       while(i < s.size())
       {
         while(i < s.size() && s[i] != ' ')
         {
            s[r++] = s[i++];
         }
         if(l < r)
         {
            reverse(s.begin() + l, s.begin() + r);
            s[r] = ' ';
            r++;
            l = r;
         }
         i++;
       }
       return s.substr(0, r - 1);
    }
};
