class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string &s1, string &s2, int i, int j, int diff) {
        if (i == s1.size() && j == s2.size()) return diff == 0;
        string key = to_string(i) + "," + to_string(j) + "," + to_string(diff);
        if (dp.count(key)) return dp[key];
        if (i < s1.size() && isdigit(s1[i])) {
            int num = 0;
            for (int k = i; k < min((int)s1.size(), i + 3); k++) {
                if (!isdigit(s1[k])) break;
                num = num * 10 + (s1[k] - '0');
                if (num > 0) {
                    if (solve(s1, s2, k + 1, j, diff + num)) return dp[key] = true;
                }
            }
        }
        if (j < s2.size() && isdigit(s2[j])) {
            int num = 0;
            for (int k = j; k < min((int)s2.size(), j + 3); k++) {
                if (!isdigit(s2[k])) break;
                num = num * 10 + (s2[k] - '0');
                if (num > 0) {
                    if (solve(s1, s2, i, k + 1, diff - num)) return dp[key] = true;
                }
            }
        }
        if (diff == 0) {
            if (i < s1.size() && j < s2.size() && isalpha(s1[i]) && isalpha(s2[j]) && s1[i] == s2[j]) {
                if (solve(s1, s2, i + 1, j + 1, 0)) return dp[key] = true;
            }
        }
        if (diff > 0 && j < s2.size() && isalpha(s2[j])) {
            if (solve(s1, s2, i, j + 1, diff - 1)) return dp[key] = true;
        }
        if (diff < 0 && i < s1.size() && isalpha(s1[i])) {
            if (solve(s1, s2, i + 1, j, diff + 1)) return dp[key] = true;
        }
        return dp[key] = false;
    }

    bool possiblyEquals(string s1, string s2) {
        dp.clear();
        return solve(s1, s2, 0, 0, 0);
    }
};