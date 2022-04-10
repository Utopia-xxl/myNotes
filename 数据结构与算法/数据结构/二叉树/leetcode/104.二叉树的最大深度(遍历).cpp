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
    // 记录最大深度
    int res = 0;
    // 记录遍历到的节点的深度
    int depth = 0;

    // 主函数
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }

    // 二叉树遍历框架
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            // 到达叶子节点，更新最大深度
            res = max(res, depth);
            return;
        }
        // 前序位置
        depth++;
        traverse(root->left);
        traverse(root->right);
        // 后序位置
        depth--;
    }
};