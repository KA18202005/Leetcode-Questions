class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26];
        for(int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(string word : words) {
            int prev = -1;
            bool possible = true;
            for(char c : word) {
                auto it = upper_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), prev);
                if(it == pos[c - 'a'].end()) {
                    possible = false;
                    break;
                }
                prev = *it;
            }
            if(possible) ans++;
        }
        return ans;
    }
};