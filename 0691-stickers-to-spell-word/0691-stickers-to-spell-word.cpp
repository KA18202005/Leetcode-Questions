class Solution {
public:
    int solve(string target, vector<vector<int>>& freq, unordered_map<string, int>& dp) {
        if(target.empty()) return 0;
        if(dp.count(target)) return dp[target];
        int ans = INT_MAX;
        for(auto& s : freq) {
            if(s[target[0] - 'a'] == 0) continue;
            vector<int> need(26, 0);
            for(char ch : target) {
                need[ch - 'a']++;
            }
            string remaining = "";
            for(int i = 0; i < 26; i++) {
                int left = max(0, need[i] - s[i]);
                while(left--) {
                    remaining += char('a' + i);
                }
            }
            int result = solve(remaining, freq, dp);
            if(result != -1) {
                ans = min(ans, 1 + result);
            }
        }
        if(ans == INT_MAX) return dp[target] = -1;
        return dp[target] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> freq;
        for(string& s : stickers) {
            vector<int> count(26, 0);
            for(char ch : s) {
                count[ch - 'a']++;
            }
            freq.push_back(count);
        }
        unordered_map<string, int> dp;
        return solve(target, freq, dp);
    }
};