/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    pair<int, int> cal(TreeNode* cur) {
        if (cur == nullptr) return {0, 0};
        auto left = cal(cur->left);
        auto right = cal(cur->right);
        int sum = left.first + right.first + cur->val;
        int n = left.second + right.second + 1;
        if (sum / n == cur->val) cnt++; 
        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        cal(root);
        return cnt; 
    }
};