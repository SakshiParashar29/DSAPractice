class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int cost = prices[0], profit = 0;

        for(int i = 0; i < n; i++){
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
        }

        return profit;
    }
};
