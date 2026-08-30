class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int total = 0, maxi = 0;
            for(int j = i; j > 0; j--) {
                total += books[j - 1][0];
                if(total > shelfWidth) break;
                maxi = max(maxi, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxi);
            }
        }
        return dp[n];
    }
};