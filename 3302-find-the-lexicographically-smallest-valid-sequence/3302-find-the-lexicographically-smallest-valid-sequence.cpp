class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int j = m - 1;
        vector<int> suffix(n + 1, m);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                suffix[i] = j;
                j--;
            }
        }
        j = 0;
        int mismatch = -1;
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) j++;
            else if (suffix[i + 1] <= j + 1) {
                mismatch = j;
                break;
            }
        }
        vector<int> ans;
        j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (j == mismatch) {
                ans.push_back(i);
                j++;
            }
            else if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
        }
        if (ans.size() < m) return {};
        return ans;
    }
};