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
    bool isValidBST(TreeNode* root) {
        // function override
        return isValidBST(root,nullptr,nullptr);
    }
    bool isValidBST(TreeNode* root,TreeNode* min, TreeNode* max){
        if(root==nullptr) return true;
        // 不合法的范围
        if(min&&min->val>=root->val) return false;
        if(max&&max->val<=root->val) return false;
        // 限制左右范围
        return isValidBST(root->left,min,root)&&isValidBST(root->right,root,max);
    }
};