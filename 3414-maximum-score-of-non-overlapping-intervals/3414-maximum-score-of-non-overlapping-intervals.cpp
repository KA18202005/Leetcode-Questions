class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int, 4>> a;
        for(int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> ans(n + 1, vector<vector<int>>(5));
        for(int i = 1; i <= n; i++) {
            int l = a[i - 1][0];
            int r = a[i - 1][1];
            int weight = a[i - 1][2];
            int index = a[i - 1][3];
            int p = 0;
            int low = 0, high = i - 2;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(a[mid][1] < l) {
                    p = mid + 1;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            for(int j = 1; j <= 4; j++) {
                dp[i][j] = dp[i - 1][j];
                ans[i][j] = ans[i - 1][j];
                long long takeWeight = dp[p][j - 1] + weight;
                vector<int> take = ans[p][j - 1];
                take.push_back(index);
                sort(take.begin(), take.end());
                if(takeWeight > dp[i][j]) {
                    dp[i][j] = takeWeight;
                    ans[i][j] = take;
                }
                else if(takeWeight == dp[i][j] && take < ans[i][j]) ans[i][j] = take;
            }
        }
        return ans[n][4];
    }
};