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
    int sum=0;
    // 后序遍历二叉树
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return sum;
    }
    vector<int> traverse(TreeNode* node){
        // vector<int>res(4) 含有4个数据分别的含义是
        // res[0] 是否是一颗搜索树 0，1
        // res[1] 搜索树中最小节点的值
        // res[2] 搜索树中最大节点的值
        // res[3] 搜索树的所有键值和
        if(node==nullptr){
            // 定义空树也是一颗搜索树
            return vector<int>{1,INT_MAX,INT_MIN,0};
        }
        vector<int> res(4);
        vector<int> left = traverse(node->left);
        vector<int> right = traverse(node->right);

        // 后序遍历二叉树

        //判断是否是搜索树的条件，左子树，右子树，加上node的树必须同时为搜索二叉树
        if(left[0]==1&&right[0]==1&&node->val>left[2]&&node->val<right[1]){
            // 构成了新的搜索二叉树
            // 更新res
            res[0] = 1;
            res[1] = min(left[1],node->val);
            res[2] = max(right[2],node->val);
            res[3] = node->val + left[3] + right[3];
            // 更新全局变量sum
            sum = max(sum,res[3]);
        }else{
            // 不满足搜索二叉树的条件
            res[0] = 0;
        }
        return res;
    }
};