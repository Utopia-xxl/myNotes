class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> onPath;
        vector<vector<int>> res;
        // 因为元素有重复，所以已nums的下标来判断是否访问过
        sort(nums.begin(),nums.end());
        backtrack(nums,onPath,res,0);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int> &onPath,vector<vector<int>> &res,int start){
        res.push_back(onPath);
        for(int i=start;i<nums.size();i++){

            // 合理剪枝，避免出现相同的子集的情况
            if(i>start&&nums[i]==nums[i-1]) continue;
            onPath.push_back(nums[i]);
            backtrack(nums,onPath,res,i+1);
            onPath.pop_back();
        }
        return;
    }
};