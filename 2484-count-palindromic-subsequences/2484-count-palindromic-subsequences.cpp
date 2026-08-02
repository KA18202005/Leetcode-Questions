class Solution {
    const int mod = 1e9 + 7;
public:
    int countPalindromes(string s) {
        int n = s.size();
        long long ans = 0;
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                vector<int> pattern = {i, j, 0, j, i};
                vector<long long> dp(6);
                dp[5] = 1;
                for(int k = 0; k < n; k++) {
                    for(int l = 0; l < 5; l++) {
                        if(s[k] == pattern[l] + '0' || l == 2) {
                            dp[l] = (dp[l] + dp[l + 1]) % mod;
                        }
                    }
                }
                ans = (ans + dp[0]) % mod;
            }
        }
        return ans;
    }
};