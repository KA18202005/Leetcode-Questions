class Solution {
private:
    string s;
    int n;
    int dp[11][1 << 10][2][2];

    int solve(int pos, int mask, int tight, int started) {
        if(pos == n) return started;
        int &ans = dp[pos][mask][tight][started];
        if(ans != -1) return ans;
        ans = 0;
        int limit = tight ? s[pos] - '0' : 9;
        for(int digit = 0; digit <= limit; digit++) {
            int newTight = tight && (digit == s[pos] - '0');
            if(!started && digit == 0) {
                ans += solve(pos + 1, mask, newTight, 0);
                continue;
            }
            if(mask & (1 << digit)) continue;
            ans += solve(pos + 1, mask | (1 << digit), newTight, 1);
        }
        return ans;
    }

public:
    int numDupDigitsAtMostN(int N) {
        s = to_string(N);
        n = s.size();
        memset(dp, -1, sizeof(dp));
        int unique = solve(0, 0, 1, 0);
        return N - unique;
    }
};