class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int i = 0, j = 0, cnt = 0, res = -1;
        
        vector<int> freq(26, 0);
        
        while(j < s.size())
        {
            if(freq[s[j] - 'a'] == 0) cnt++;
            
            freq[s[j] - 'a']++;
            
            while(cnt > k)
            {
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0) cnt--;
                
                i++;
            }
            if(cnt == k)
               res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
