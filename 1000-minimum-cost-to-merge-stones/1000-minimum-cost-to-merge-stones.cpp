class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
         for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(int mid = i; mid < j; mid += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }
                if((len - 1) % (k - 1) == 0) {
                    int sum = pref[j + 1] - pref[i];
                    dp[i][j] += sum;
                }
            }
        }
        return dp[0][n - 1];
    }
};