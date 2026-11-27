class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mini = 1e9;
        vector<int> freq(n, 0);
        for(int i = 0; i < n; i++) {
            mini = min(mini, items[i][1]);
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) freq[i]++;
            }
        }
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            int wt = items[i][1];
            int val = 1 + freq[i];
            for(int w = budget; w >= wt; w--) {
                if (dp[w - wt] != -1) {
                    dp[w] = max(dp[w], dp[w - wt] + val);
                }
            }
        }
        int ans = 0;
        for(int w = 0; w <= budget; w++) {
            if(dp[w] != -1) {
                int remaining = budget - w;
                int add = remaining / mini;
                int total = dp[w] + add;
                ans = max(ans, total);
            }
        }
        return ans;
    }
};