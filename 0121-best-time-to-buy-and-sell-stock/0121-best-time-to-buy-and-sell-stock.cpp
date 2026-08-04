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

        // //Two pointer approach
        // int left = 0; // left = Buy
        // int right = 1; // right = Sell
        // int maxProfit = 0;

        // while(right < prices.size()) {
        //     if(prices[left] > prices[right]) {
        //         left = right;
        //     }
        //     else {
        //         maxProfit = max(maxProfit, prices[right] - prices[left]);
        //     }
        //     right++;
        // }
        // return maxProfit;
};