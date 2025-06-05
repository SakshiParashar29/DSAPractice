class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, res = 0;
        long long cost = 0;

        while(j < s.size())
        {
           cost += abs((s[j] - 'a') - (t[j] -'a'));

           while(i <= j && cost > maxCost)  
           {
               cost -= abs((s[i] - 'a') - (t[i] -'a'));
               i++;
           }
           res = max(res, j - i + 1);
           j++;
        }
        return res;
    }
};
