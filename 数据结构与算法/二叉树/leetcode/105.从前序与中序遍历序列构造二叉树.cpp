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
    int rootInx=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int l,int r){
        if(l>r){
            return nullptr;
        }
        int index = -1;
        for(int i=l;i<=r;i++){
            if(inorder[i]==preorder[rootInx]){
                index = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(preorder[rootInx++]);
        node->left = build(preorder,inorder,l,index-1);
        node->right = build(preorder,inorder,index+1,r);
        return node;
    }
};