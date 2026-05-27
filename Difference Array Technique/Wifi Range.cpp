class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int n = s.length();
        
        vector<int> temp(n, 0);
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                int l = max(0, i - x);
                int r = min(i + x, n - 1);
                
                temp[l] += 1;
                if(r + 1 < n) temp[r + 1] -= 1;
            }
        }
        
        for(int j = 1; j < n; j++){
            temp[j] += temp[j - 1];
        }
        
        for(int i = 0; i < n; i++){
            if(temp[i] == 0) return false;
        }
        
        return true;
    }
};
