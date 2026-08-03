class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(3, 0);
        for(int i = n - 1; i >= 0; i--) {
            int cur_sum = 0;
            int max_dif = INT_MIN;
            for(int k = 1; k <= 3 && i + k - 1 < n; k++) {
                cur_sum += stoneValue[i + k - 1];
                int rem_dif = dp[(i + k) % 3];
                int dif = cur_sum - rem_dif;
                max_dif = max(max_dif, dif);
            }
            dp[i % 3] = max_dif;
        }
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};