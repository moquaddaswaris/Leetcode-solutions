class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int p : prices) {
            minPrice = min(minPrice, p);

            int profit = p - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};