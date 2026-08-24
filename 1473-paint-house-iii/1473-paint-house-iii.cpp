class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INF)));
         if(houses[0] != 0) {
            dp[0][houses[0]][1] = 0;
        }
        else {
            for(int color = 1; color <= n; color++) {
                dp[0][color][1] = cost[0][color - 1];
            }
        }
        for(int i = 1; i < m; i++) {
            for(int prev = 1; prev <= n; prev++) {
                for(int group = 1; group <= target; group++) {
                    if(dp[i - 1][prev][group] == INF)
                        continue;
                    if(houses[i] != 0) {
                        int color = houses[i];
                        int newGroups = group + (color != prev);
                        if(newGroups <= target) {
                            dp[i][color][newGroups] = min(dp[i][color][newGroups], dp[i - 1][prev][group]);
                        }
                    }
                    else {
                        for(int color = 1; color <= n; color++) {
                            int newGroups = group + (color != prev);
                            if(newGroups > target)
                                continue;
                            int newCost = dp[i - 1][prev][group] + cost[i][color - 1];
                            dp[i][color][newGroups] = min(dp[i][color][newGroups], newCost);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for(int color = 1; color <= n; color++) {
            ans = min(ans, dp[m - 1][color][target]);
        }
        return ans == INF ? -1 : ans;
    }
};