class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        int n = changed.size();

        vector<int> res;
        unordered_map<int, int> mp;
        sort(changed.begin(), changed.end());
        for(int i = 0; i < n; i++)
        {
            mp[changed[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(mp[changed[i]] == 0) continue;
            if(mp.find(changed[i] * 2) != mp.end() && mp[changed[i] * 2]!=0)
            {
                res.push_back(changed[i]);
                mp[changed[i] * 2]--;
                mp[changed[i]]--;
            }
            else
              return {};
        }
        return res;
    }
};
