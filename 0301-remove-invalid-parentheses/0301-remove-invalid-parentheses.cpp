class Solution {
    vector<string> ans;
public:
    void solve(string &s, int idx, int left, int right, int open, string curr) {
        if (idx == s.size()) {
            if (open == 0 && left == 0 && right == 0) ans.push_back(curr);
            return;
        }
        if (s[idx] == '(' && left > 0) {
            solve(s, idx + 1, left - 1, right, open, curr);
        }
        if (s[idx] == ')' && right > 0) {
            solve(s, idx + 1, left, right - 1, open, curr);
        }
        if (s[idx] != '(' && s[idx] != ')') {
            solve(s, idx + 1, left, right, open, curr + s[idx]);
        }
        else if (s[idx] == '(') {
            solve(s, idx + 1, left, right, open + 1, curr + s[idx]);
        }
        else if (open > 0) {
            solve(s, idx + 1, left, right, open - 1, curr + s[idx]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        solve(s, 0, left, right, 0, "");
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};