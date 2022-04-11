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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            int queLen = que.size();
            level++;
            for(int i=0;i<queLen;i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
                if(temp->left==nullptr&&temp->right==nullptr){
                    // 叶子节点，最先访问到的叶子节点一定是层级最低的
                    return level;
                }
            }
        }
        return level;
    }
};