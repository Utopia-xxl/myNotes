class Solution {
public:
    int sum=0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 求子集的和为target
        vector<int> onPath;
        vector<vector<int>> res;
        // 因为元素有重复，所以已nums的下标来判断是否访问过
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,onPath,res,0,target);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int> &onPath,vector<vector<int>> &res,int start,int target){
        // 剪枝
            if(sum>target) return;
            if(sum==target) {
                res.push_back(onPath);
                return;
            }
        for(int i=start;i<nums.size();i++){
            // 合理剪枝，避免出现相同的子集的情况
            if(i>start && nums[i]==nums[i-1]) continue;
            
            sum+=nums[i];
            onPath.push_back(nums[i]);
            backtrack(nums,onPath,res,i+1,target);
            onPath.pop_back();
            sum-=nums[i];
        }
        return;
    }
};