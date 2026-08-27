class Solution {
private:
    bool dfs(int idx, bool equal, string curr, vector<int>& freq, string& target, string& ans, int n) {
        if(idx == n) {
            if(curr > target) {
                ans = curr;
                return true;
            }
            return false;
        }
        char start = equal ? target[idx] : 'a';
        for(char ch = start; ch <= 'z'; ++ch) {
            if(freq[ch - 'a'] == 0) continue;
            freq[ch - 'a']--;
            bool nxteq = equal && (ch == target[idx]);
            if(!equal && ans.empty()) {
                string temp = curr + ch;
                for(int k = 0; k < 26; ++k) {
                    temp.append(freq[k], 'a' + k);
                }
                ans = temp;
                freq[ch - 'a']++;
                return true;
            }
            if(dfs(idx + 1, nxteq, curr + ch, freq, target, ans, n)) return true;
            freq[ch - 'a']++;
        }
        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        int n = s.size();
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        bool found = dfs(0, true, "", freq, target, ans, n);
        return found ? ans : "";
    }
};