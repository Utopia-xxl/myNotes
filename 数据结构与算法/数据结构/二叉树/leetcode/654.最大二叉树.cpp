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
    int findMaxNum (vector<int>& nums,int l, int r){
        // 返回数组中最大值的下标
        int MaxNum = INT_MIN;
        int inx;
        for(int i=l;i<=r;i++){
            if(nums[i]>MaxNum){
                MaxNum = nums[i];
                inx = i;
            }
        }
        return inx;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums, int l, int r){
        if(l>r){
            return NULL;
        }
        int index = findMaxNum(nums,l,r);
        TreeNode* root = new TreeNode(nums[index]);
        root->left = build(nums,l,index-1);
        root->right = build(nums,index+1,r);
        return root;
    }
};