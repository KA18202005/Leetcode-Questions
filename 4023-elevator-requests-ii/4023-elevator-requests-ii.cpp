class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        constexpr long long INF = 1e18;
        
        bool st = false;
        for(int r : requests) {
            if(r == start) {
                st = true;
                break;
            }
        }
        if(!st) requests.push_back(start);

        sort(requests.begin(), requests.end());
        int m = requests.size();
        int sidx = lower_bound(requests.begin(), requests.end(), start) - requests.begin();

        // dp[i][j][0] = min penalty for range [i, j] ending at the left (i)
        // dp[i][j][1] = min penalty for range [i, j] ending at the right (j)
        vector<vector<array<long long, 2>>> dp(m, vector<array<long long, 2>> (m, {INF, INF}));
        
        // Base case: Starting at 'start' costs 0 time
        dp[sidx][sidx][0] = 0;
        dp[sidx][sidx][1] = 0;

        for(int len = 1; len < m; ++len) {
            for(int i = 0; i + len - 1 < m; ++i) {
                int j = i + len - 1;
                
                // Number of requests still waiting to be fulfilled
                int rem = m - len; 
                
                // Expand Left: Move to i - 1
                if(i > 0) {
                    // From left (i)
                    dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][0] + 1LL * (requests[i] - requests[i - 1]) * rem);
                    // From right (j)
                    dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][1] + 1LL * (requests[j] - requests[i - 1]) * rem);
                }
                
                // Expand Right: Move to j + 1
                if(j < m - 1) {
                    // From left (i)
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + 1LL * (requests[j + 1] - requests[i]) * rem);
                    // From right (j)
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + 1LL * (requests[j + 1] - requests[j]) * rem);
                }
            }
        }

        return min(dp[0][m - 1][0], dp[0][m - 1][1]);
    }
};