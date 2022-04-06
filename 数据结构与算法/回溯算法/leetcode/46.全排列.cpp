class Solution {
public:
    vector<vector<int>> res; // 存放所有的结果
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track; // 存放一种结果
        // 利用数组下标判断是否访问过
        vector<bool> visited(nums.size(),false);
        backtrack(nums,track,visited);
        return res;
    }

    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素（used[i] 为 false）
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(vector<int> &nums, vector<int> &track, vector<bool> &visited){
        // 参数要传引用而不要传值
        if(nums.size()==track.size()){
            // 结束，并且存下结果
            res.push_back(track);
        }
        for(int i=0;i<nums.size();i++){
            // 遍历所有节点
            if(visited[i]){
                // 已经遍历过了，返回
                continue;
            }
            // 选择这个数
            visited[i] = true;
            track.push_back(nums[i]);
            backtrack(nums,track,visited);
            // 回退，移除这个数
            visited[i] = false;
            track.pop_back();
        }
        return;
    }
};