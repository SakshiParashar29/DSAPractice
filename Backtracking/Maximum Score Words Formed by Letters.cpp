class Solution {
public: 
    int maxScore, n;
    void solve(int i, int currScore,vector<string>& words, vector<int>& score, vector<int>& freq)
    {
        maxScore = max(currScore, maxScore);
        if(i >= n)
           return;

        int j = 0;
        int tempScore = 0;
        vector<int>tempFreq = freq;

        while(j < words[i].length())
        {
            char ch = words[i][j];
            tempFreq[ch - 'a']--;

            tempScore += score[ch - 'a'];
            if(tempFreq[ch - 'a'] < 0)
               break;

            j++;
        }
        if(j == words[i].length())
        {
            solve(i + 1, currScore + tempScore, words, score, tempFreq);
        }

        solve(i + 1, currScore, words, score, freq);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        n = words.size();
        maxScore = INT_MIN;
        for(char& ch : letters)
        {
            freq[ch - 'a']++;
        }
        
        solve(0, 0, words, score, freq);
        return maxScore;
    }
};
