class Solution {
private:
    void solve(int ind, vector<string>& ans, string& ds, unordered_map<char, string>& mpp, string digits) {
        if(ind == digits.length()) {
            ans.push_back(ds);
            return;
        }
        string val = mpp[digits[ind]];
        for(int j = 0; j < val.length(); j++) {
            ds.push_back(val[j]);
            solve(ind + 1, ans, ds, mpp, digits);
            ds.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        string ds;
        unordered_map<char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        solve(0, ans, ds, mpp, digits);
        return ans;
    }
};