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
    int maxDiameter=0;
    int maxDepth(TreeNode* node){
        if(node==nullptr) return 0;
        // 分别求左右子树的深度
        int leftMax = traverse(node->left);
        int rightMax = traverse(node->right);
        // 求直径
        int maxd = leftMax+rightMax;
        // 更新全局最大直径
        maxDiameter = max(maxd,maxDiameter);
        return max(leftMax,rightMax)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }
};