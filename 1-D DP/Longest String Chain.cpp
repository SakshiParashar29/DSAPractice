// Approach 1 - Recursive
class Solution {
public:
    static bool myFunction(string& word1, string& word2)
    {
        return word1.length() < word2.length();
    }
    bool isPredecessor(string word1, string word2)
    {
        if(word1.length() + 1 != word2.length())
           return false;
        int i = 0, j = 0;
        while(j < word2.size())
        {
            while(i < word1.length() && word1[i] == word2[j])
            {
                i++;
            }
            j++;
        }
        return (i == word1.size());
    }
    int solve(int i, int prev, vector<string>& words)
    {
        if(i >= words.size())
           return 0;

        int take = 0;
        if(prev == -1 || isPredecessor(words[prev], words[i]))
        {
             take = 1 + solve(i + 1, i, words);
        }
        int skip = solve(i + 1,prev, words);

        return max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
       sort(begin(words), end(words), myFunction);
       return solve(0, -1, words);
    }
};


//Memoization
class Solution {
public:
    static bool myFunction(string& word1, string& word2)
    {
        return word1.length() < word2.length();
    }
    int dp[1001][1001];
    bool isPredecessor(string word1, string word2)
    {
        if(word1.length() + 1 != word2.length())
           return false;
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size())
        {
            if(word1[i] == word2[j])
            {
                i++;
            }
            j++;
        }
        return (i == word1.size());
    }
    int solve(int i, int prev, vector<string>& words)
    {
        if(i >= words.size())
           return 0;
        if(prev != -1 && dp[i][prev] != -1)
           return dp[i][prev];
        int take = 0;
        if(prev == -1 || isPredecessor(words[prev], words[i]))
        {
             take = 1 + solve(i + 1, i, words);
        }
        int skip = solve(i + 1,prev, words);
        
        if(prev != -1)
           dp[i][prev] = max(take, skip);
        return max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof(dp));
       sort(begin(words), end(words), myFunction);
       return solve(0, -1, words);
    }
};

//Bottom-up Approach
class Solution {
public:
    static bool myFunction(string& word1, string& word2)
    {
        return word1.length() < word2.length();
    }
    bool isPredecessor(string word1, string word2)
    {
        if(word1.length() + 1 != word2.length())
           return false;
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size())
        {
            if(word1[i] == word2[j])
            {
                i++;
            }
            j++;
        }
        return (i == word1.size());
    }
    int longestStrChain(vector<string>& words) {
       sort(begin(words), end(words), myFunction);
       vector<int> dp(words.size(), 1);
       int maxLen = 1;
       for(int i = 0; i < words.size(); i++)
       {
           for(int j = 0; j <= i; j++)
           {
              if(isPredecessor(words[j], words[i]))
              {
                  dp[i] = max(dp[i], dp[j] + 1);
                  maxLen = max(maxLen, dp[i]);
              }
           }
       }
       return maxLen;
    }
};
