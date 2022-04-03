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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, 0, preorder.size() - 1,
                postorder, 0, postorder.size() - 1);
    }
    // 结果不唯一，因此如果只有一个节点默认为左子树
    TreeNode* build(vector<int> preorder, int preStart, int preEnd,vector<int> postorder, int postStart, int postEnd){
        if(postStart>postEnd){
            return nullptr;
        }
        if(preStart==preEnd){
            return new TreeNode(preorder[preStart]);
        }
        int rootVal = preorder[preStart];
        int leftVal = preorder[preStart+1];
        // 从后序的数组中找出leftVal的索引，划分左右子树，leftVal节点也包括子树组中
        int index = 0;
        for(int i=postStart;i<=postEnd;i++){
            if(postorder[i]==leftVal){
                index = i;
                break;
            }
        }
        // +1 是因为leftVal只是辅助划分，index的节点也在左子树
        int leftCount = index - postStart + 1;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder,preStart+1,preStart+leftCount,postorder,postStart,index);
        root->right = build(preorder,preStart+leftCount+1,preEnd,postorder,index+1,postEnd-1);
        return root;
    }
};