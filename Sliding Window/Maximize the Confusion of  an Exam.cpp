class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0, cnt = 0, tval = 0, fval = 0;

        while(j < answerKey.size())
        {
            if(answerKey[j] == 'F')
                cnt++;

            while(cnt > k)
            {
                if(answerKey[i] == 'F')
                   cnt--;
                i++;
            }
            tval = max(tval, j - i + 1);
            j++;
        }
        i = 0, j = 0, cnt = 0;
        while(j < answerKey.size())
        {
            if(answerKey[j] == 'T')
                cnt++;

            while(cnt > k)
            {
                if(answerKey[i] == 'T')
                   cnt--;
                i++;
            }
            fval = max(fval, j - i + 1);
            j++;
        }
        return max(tval, fval);
    }
};
