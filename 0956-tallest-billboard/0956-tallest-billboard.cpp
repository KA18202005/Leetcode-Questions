class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;
        for(int x: rods) {
            vector<int> next = dp;
            for(int d = 0; d <= sum; d++) {
                if(dp[d] == -1) continue;
                next[d] = max(next[d], dp[d]);
                next[d + x] = max(next[d + x], dp[d]);
                next[abs(d - x)] = max(next[abs(d - x)], dp[d] + min(d, x));
            }
            dp = next;
        }
        return dp[0];
    }
};