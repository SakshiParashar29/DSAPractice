int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int i = 0, j = 0, res = 0, cnt = 0;
    
    vector<int> freq(26, 0);

    while(j < n)
    {
        if(freq[s[j] - 'a'] == 0) cnt++;

        freq[s[j] - 'a']++;

        while(cnt > 2)
        {
            freq[s[i] - 'a']--;
            if(freq[s[i] - 'a'] == 0)
               cnt--;
            i++;
        }
        res = max(res, j - i + 1);
        j++;
    }
    return res;
}
