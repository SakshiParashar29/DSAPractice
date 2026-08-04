class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        int n1 = n/2;
        int n2 = n - n1;

        vector<int> A;
        vector<int> B;

        for(int i = 0; i < pow(2, n1); i++){
            int sum = 0;
            for(int mask = 0; mask < n1; mask++){
                if(i & (1 << mask)){
                    sum += nums[mask];
                }
            }
            A.push_back(sum);
        }

        for(int i = 0; i < pow(2, n2); i++){
            int sum = 0;
            for(int mask = 0; mask < n2; mask++){
                if(i & (1 << mask)){
                    sum += nums[mask + n1];
                }
            }
            B.push_back(sum);
        }

        sort(begin(B), end(B));

        int ans = INT_MAX;

        for(int i = 0; i < A.size(); i++){
            int sum1 = A[i];
            int need = goal - sum1;
            int idx = lower_bound(begin(B), end(B), need) - begin(B);

            if(idx < B.size())
            {
                int sum2 = B[idx];
                int total = sum1 + sum2;
                ans = min(ans, abs(goal - total));
            }

            if(idx > 0){
                int sum2 = B[idx - 1];
                int total = sum1 + sum2;
                ans = min(ans, abs(goal - total));
            }
        }
        return ans;
    }
};
