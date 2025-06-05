class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, res = 0;
        vector<int> freq(26, 0);
        
        while(j < s.length())
        {
            freq[s[j++] - 'A']++;

            int maxfreq = *max_element(begin(freq), end(freq));
            while(j - i - maxfreq > k)
            {
                freq[s[i] - 'A']--;
                i++;
            }
            res = max(res, j - i);
            // j++;
        }
        return res;
    }
};
