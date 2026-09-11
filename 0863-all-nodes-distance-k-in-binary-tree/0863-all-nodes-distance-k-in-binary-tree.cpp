/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent, target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int cur_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (cur_level++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left && !vis[cur->left]) {
                    q.push(cur->left);
                    vis[cur->left] = true;
                }
                if (cur->right && !vis[cur->right]) {
                    q.push(cur->right);
                    vis[cur->right] = true;
                }
                if (parent[cur] && !vis[parent[cur]]) {
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};