class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> st;
        for(string w : startWords) {
            int mask = 0;
            for(char c : w) {
                mask |= (1 << (c - 'a'));
            }
            st.insert(mask);
        }
        int ans = 0;
        for(string w : targetWords) {
            int mask = 0;
            for(char c : w) {
                mask |= (1 << (c - 'a'));
            }
            for(char c : w) {
                int newMask = mask ^ (1 << (c - 'a'));
                if(st.count(newMask)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};