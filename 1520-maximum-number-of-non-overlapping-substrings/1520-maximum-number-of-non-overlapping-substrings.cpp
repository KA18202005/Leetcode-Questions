class Solution {
private:
    int check(string& s, int i, vector<int>& start, vector<int>& end) {
        int right = end[s[i] - 'a'];
        for(auto j = i; j <= right; j++) {
            if(start[s[j] - 'a'] < i) return -1;
            right = max(right, end[s[j] - 'a']);
        }
        return right;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26, INT_MAX), end(26, INT_MAX);
        vector<string> ans;
        for(int i = 0; i < s.size(); i++) {
            start[s[i] - 'a'] = min(start[s[i] - 'a'], i);
            end[s[i] - 'a'] = i;
        }
        int right = -1;
        for(int i = 0; i < s.size(); i++) {
            if(i == start[s[i] - 'a']) {
                int new_right = check(s, i, start, end);
                if(new_right != -1) {
                    if(i > right) ans.push_back("");
                    right = new_right;
                    ans.back() = s.substr(i, right - i + 1);
                }
            }
        }
        return ans;
    }
};