// TC : O(n * klogK) klogk for sorting each string of strs and n for size of string. SC : O(n * m) where n is length of strs and m is length of each string in strs at 0 to n - 1 index
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       
       unordered_map<string,vector<string>> mp;
       for(int i = 0; i < strs.size(); i++)
       {
          string str = strs[i];
          sort(str.begin(), str.end());
          mp[str].push_back(strs[i]);
       }
       for(auto &it : mp)
       {
          res.push_back(it.second);
       }
       return res;
    }
};


// SECOND APPROACH
class Solution {
public:
    string generate(string str)
    {
        int arr[26] = {0};
        for(int i = 0; i < str.size(); i++)
        {
            arr[str[i] - 'a']++;
        }
        string res;
        for(int i = 0; i < 26; i++)
        {
            int freq = arr[i];
            if(freq > 0)
               res += string(freq, i + 'a');
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> res;
       unordered_map<string,vector<string>> mp;

       for(int i = 0; i < strs.size(); i++)
       {
          string newWord = generate(strs[i]);
          mp[newWord].push_back(strs[i]);
       }
       for(auto &it : mp)
       {
          res.push_back(it.second);
       }
       return res;
    }
};
