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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<TreeNode*> queue;

        queue.push(root);
        // 从上到下遍历二叉树的每一层
        while(!queue.empty()){
            int qLen = queue.size();
            result.push_back(vector<int>());
            // 从左到右遍历每一层的每个节点
            for(int i=0;i<qLen;i++){
                TreeNode* cur = queue.front();
                queue.pop();
                result[result.size()-1].push_back(cur->val);
                // 将下一层节点放入队列
                if(cur->left) queue.push(cur->left);
                if(cur->right) queue.push(cur->right);
            }
        }
        return result;
    }
};