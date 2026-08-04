class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;

        int total = accumulate(begin(nums), end(nums), 0);

        vector<vector<int>> A(n + 1);
        vector<vector<int>> B(n + 1);

        for(int mask = 0; mask < (1 << n); mask++){
            int sum = 0, k = 0;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    sum += nums[i];
                    k++;
                }
            }
            A[k].push_back(sum);
        }

        for(int mask = 0; mask < (1 << n); mask++){
            int sum = 0, k = 0;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    sum += nums[i + n];
                    k++;
                }
            }
            B[k].push_back(sum);
        }

        for(int i = 0; i < B.size(); i++){
            sort(begin(B[i]), end(B[i]));
        }

        int ans = INT_MAX;

        for(int k = 0; k <= n; k++){
            int m = n - k;
            
            for(int& leftSum : A[k]){
                int need = (total - (2*leftSum))/2;

                int low = lower_bound(begin(B[m]), end(B[m]), need) - begin(B[m]);

                if(low < B[m].size()){
                    int rightSum = B[m][low];
                    ans = min(ans, abs(2*(leftSum + rightSum) - total));
                }

                if(low - 1 >= 0){
                    int rightSum = B[m][low - 1];
                    ans = min(ans, abs(2*(leftSum + rightSum) - total));
                }
            }
        }
        return ans;
    }
};
