class Solution {
public:
    long long solve(int mask, int last, int start, int n, vector<vector<int>>& req, vector<vector<long long>>& dp) {
        int prevMask = mask ^ (1 << last);
        // Base case: last is the first request
        if(prevMask == 0) {
            long long time = abs(start - req[last][1]);
            // Cannot complete before the request time
            time = max(time, (long long)req[last][0]);
            return dp[mask][last] = time;
        }
        // Already calculated
        if(dp[mask][last] != -1) return dp[mask][last];
        long long curRes = LLONG_MAX;
        // Try every possible previous request
        for(int i = 0; i < n; i++) {
            // Request i must be present in prevMask
            if(!(prevMask & (1 << i))) continue;
            long long prevTime = solve(prevMask, i, start, n, req, dp);
            // Travel from request i to request last
            long long travel = abs(req[i][1] - req[last][1]);
            // Time to complete the current request
            long long time = max(prevTime + travel, (long long)req[last][0]);
            curRes = min(curRes, time);
        }
        return dp[mask][last] = curRes;
    }

    long long elevatorRequests(int n, int start, vector<vector<int>>& req) {
        int m = req.size();
        vector<vector<long long>> dp(1 << m, vector<long long>(m, -1));
        int full = (1 << m) - 1;
        long long res = LLONG_MAX;
        // Try every request as the last request
        for(int i = 0; i < m; i++) {
            res = min(res, solve(full, i, start, m, req, dp));
        }
        return res;
    }
};