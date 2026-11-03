class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadNbuy, aheadbuy, curbuy, curNbuy;
        aheadNbuy = aheadbuy = 0;
        for(int ind = n - 1; ind >= 0; ind--) {
            curNbuy = max(prices[ind] - fee + aheadbuy, aheadNbuy);
            curbuy = max(-prices[ind] + aheadNbuy, aheadbuy);
            aheadbuy = curbuy;
            aheadNbuy = curNbuy;
        }
        return aheadbuy;
    }
};