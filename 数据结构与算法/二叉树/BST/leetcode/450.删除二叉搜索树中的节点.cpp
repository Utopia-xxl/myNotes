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
    // 一共有三种情况：
    // 情况 1：A 恰好是末端节点，两个子节点都为空，那么它可以当场去世了。
    // 情况 2：A 只有一个非空子节点，那么它要让这个孩子接替自己的位置。
    // 情况 3：A 有两个子节点，麻烦了，为了不破坏 BST 的性质，A 必须找到左子树中最大的那个节点，或者右子树中最小的那个节点来接替自己。我们以第二种方式讲解。
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key){
            // 同时处理情况1，2
            if(root->left==nullptr) return root->right;
            if(root->right==nullptr) return root->left;

            // 处理情况3
            // 找右子树最小的节点来替换
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            // 再执行一次情况一，逻辑上删掉节点，实际上只是交换了val
            root->right = deleteNode(root->right,minNode->val);
        }else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
    TreeNode* getMin(TreeNode* node){
        // BST最左边的就是最小的
        while(node->left) node = node->left;
        return node;
    }
};