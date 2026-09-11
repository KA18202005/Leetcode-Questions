struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isWord = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto &word : wordDict) trie.insert(word);
        unordered_map<int, vector<string>> memo;
        return dfs(0, s, trie.root, memo);
    }

private:
    vector<string> dfs(int index, string &s, TrieNode* root, unordered_map<int, vector<string>> &memo) {
        if (index == s.size()) return {""};
        if (memo.count(index)) return memo[index]; 
        TrieNode* node = root;
        vector<string> res;
        for (int i = index; i < s.size(); i++) {
            char ch = s[i];
            if (!node->children.count(ch)) break;
            node = node->children[ch]; 
            if (node->isWord) {
                vector<string> tails = dfs(i + 1, s, root, memo);
                for (string &tail : tails) {
                    if (tail.empty()) res.push_back(s.substr(index, i - index + 1));
                    else res.push_back(s.substr(index, i - index + 1) + " " + tail);
                }
            }
        }
        return memo[index] = res;
    }
};