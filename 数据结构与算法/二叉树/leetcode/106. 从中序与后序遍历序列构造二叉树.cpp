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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& postorder,int prel,int prer,vector<int>& inorder,int l,int r){
        if(l>r){
            return nullptr;
        }
        int index = -1;
        for(int i=l;i<=r;i++){
            if(inorder[i]==postorder[prer]){
                index = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(inorder[index]);
        node->left = build(postorder,prel,prel+index-l-1,inorder,l,index-1);
        node->right = build(postorder,prer-r+index,prer-1,inorder,index+1,r);
        return node;
    }
};