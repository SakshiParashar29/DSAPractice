class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, pair<int, int>>> temp;
        
        double res = 0.0;
        int n = val.size();
        
        for(int i = 0; i < n; i++){
            double value = (double)val[i]/wt[i];
            temp.push_back({value, {val[i], wt[i]}});
        }
        
        sort(begin(temp),end(temp), [](auto& a, auto& b){
            return a.first > b.first;
        });
        
        for(auto& it : temp){
            int w = it.second.second;
            int v = it.second.first;
            
            if(w <= capacity){
                res += v;
                capacity -= w;
            }else if(capacity > 0){
                res += (double) capacity * v / w;
                break;
            }
        }
        return res;
    }
};
