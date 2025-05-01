class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs), [](const vector<int>& a, const vector<int>& b)
       {
            return a[1] < b[1];
       });
        
        int pair = 1, prev = pairs[0][1];
        for(int i = 1; i < pairs.size(); i++)
        {
            int r = pairs[i][0];
            if(r > prev)
            {
               pair++;
               prev = pairs[i][1];
            }
        }
        return pair;
    }
};
