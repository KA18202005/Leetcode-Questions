class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(curr->child[idx] == nullptr) {
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }

    bool dfs(string &word, int start, int count, vector<int>& dp) {
        if(start == word.size()) {
            return count >= 2;
        }
        if(dp[start] != -1) {
            return dp[start];
        }
        TrieNode* curr = root;
        for(int i = start; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(curr->child[idx] == nullptr) {
                break;
            }
            curr = curr->child[idx];
            if(curr->isEnd) {
                if(dfs(word, i + 1, count + 1, dp)) {
                    return dp[start] = 1;
                }
            }
        }
        return dp[start] = 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string &word : words) {
            if(!word.empty()) {
                insert(word);
            }
        }
        vector<string> ans;
        for(string &word : words) {
            if(word.empty()) continue;
            vector<int> dp(word.size(), -1);
            if(dfs(word, 0, 0, dp)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};