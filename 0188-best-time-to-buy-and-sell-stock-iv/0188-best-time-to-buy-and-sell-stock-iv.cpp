class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2 * k + 1, 0), cur(2 * k + 1, 0);
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
                if(tranNo % 2 == 0) 
                    cur[tranNo] = max(-prices[ind] + after[tranNo + 1], after[tranNo]);
                else
                    cur[tranNo] = max(prices[ind] + after[tranNo + 1], after[tranNo]);
            }
            after = cur;
        }
        return after[0];
    }
};