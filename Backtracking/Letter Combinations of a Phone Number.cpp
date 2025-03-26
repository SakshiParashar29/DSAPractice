// TC : O(4^n) && SC : O(4^n + n)
class Solution {
public:
    vector<string> res;
    void solve(int idx, unordered_map<char, string>& phone, string& digits, string& temp)
    {
        if(idx >= digits.length())
        {
            res.push_back(temp);
            return;
        }
        
        string word = phone[digits[idx]];
        for(int i = 0; i < word.length(); i++)
        {
            temp.push_back(word[i]);
            solve(idx + 1, phone, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";

        int n = digits.length();
        if(n == 0)
           return res;
        string temp = "";
        solve(0, phone, digits, temp);
        return res;
    }
};
