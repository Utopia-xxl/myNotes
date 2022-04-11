class Solution {
public:
    vector<vector<int>> res;
    // 记录回溯算法的递归路径
    vector<int> track;
    vector<vector<int>> subsets(vector<int>& nums) {
        // 利用回溯的遍历模版
        backtrack(nums,0);
        return res;
    }
    void backtrack(vector<int> &nums,int start){
        // 前序位置，每个节点的值都是一个子集
        res.push_back(track);
        for(int i = start;i<nums.size();i++){
            // 路径选择
            track.push_back(nums[i]);
            // 通过start参数控制树枝的遍历，避免产生重复的子集
            backtrack(nums,i+1);
            // 撤销选择
            track.pop_back();
        }
        return;
    }
};