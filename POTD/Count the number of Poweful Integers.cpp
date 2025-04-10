class Solution {
public:
    long long solve(string& finish, int& limit, string& s)
    {
        int suffixLen = s.length();
        int finishLen = finish.length();
        
        if(finishLen < suffixLen)
           return 0;
        
        long long cnt = 0;
        string remStr = finish.substr(finishLen - suffixLen);
        
        int remLen = finishLen - suffixLen;
        for(int i = 0; i < remLen; i++)
        {
            int digit = finish[i] - '0';
            if(digit <= limit)
            {
                cnt += digit * pow(limit + 1, remLen - i - 1);
            }
            else
            {
                cnt += pow(limit + 1, remLen - i);
                return cnt;
            }
        }
        if(remStr >= s)
           cnt += 1;

        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);

        return (solve(finishStr, limit, s) - solve(startStr, limit, s));
    }
};
