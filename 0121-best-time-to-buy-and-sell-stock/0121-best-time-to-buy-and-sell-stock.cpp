class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int pmaxProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            pmaxProfit = max(pmaxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return pmaxProfit;
    }
};