class Solution {
public:
    int numDecodings(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        if (s[0] == '*') dp[1] = 9;
        else if (s[0] != '0') dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            char prev = s[i - 2];
            char cur = s[i - 1];
            long long singleWays = 0;
            if (cur == '*') singleWays = 9;
            else if (cur != '0') singleWays = 1;
            dp[i] = (dp[i] + dp[i - 1] * singleWays) % MOD;
            long long pairWays = 0;
            if (prev == '*' && cur == '*') pairWays = 15;
            else if (prev == '*') {
                if (cur >= '0' && cur <= '6') pairWays = 2;
                else pairWays = 1;
            }
            else if (cur == '*') {
                if (prev == '1') pairWays = 9;
                else if (prev == '2') pairWays = 6;
            }
            else {
                int num = (prev - '0') * 10 + (cur - '0');
                if (num >= 10 && num <= 26) pairWays = 1;
            }
            dp[i] = (dp[i] + dp[i - 2] * pairWays) % MOD;
        }
        return dp[n];
    }
};