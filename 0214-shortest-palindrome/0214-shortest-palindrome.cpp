class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> next(n);
        for(int i = 1, j = 0; i < n; ++i){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]) ++j;
            next[i] = j;
        }
        int j = 0;
        for(int i =  n - 1; i >= 0; --i){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]) ++j;
        }
        if(j == n) return s;
        string left = s.substr(j);
        reverse(left.begin(), left.end());
        return left + s;
    }
};