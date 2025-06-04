class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        if(s.size() == 0) return 0;
        int i = 0, j = 0, cnt = 0, res = 1;
        while(j < s.length())
        {
            freq[s[j]]++;
            while(freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
