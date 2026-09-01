class Solution {
public:
    struct Node {
        Node* child[26];
        int cnt;
        Node() {
            cnt = 0;
            for(int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        for(string word : words) {
            Node* cur = root;
            for(char ch : word) {
                int x = ch - 'a';
                if(cur->child[x] == nullptr) cur->child[x] = new Node();
                cur = cur->child[x];
                cur->cnt++;
            }
        }
        vector<int> ans;
        for(string word : words) {
            Node* cur = root;
            int score = 0;
            for(char ch : word) {
                cur = cur->child[ch - 'a'];
                score += cur->cnt;
            }
            ans.push_back(score);
        }
        return ans;
    }
};