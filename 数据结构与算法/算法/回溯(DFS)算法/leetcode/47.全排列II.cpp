class Solution {
public:
    vector<int> visited;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size());
        vector<int> onPath;
        sort(nums.begin(),nums.end());
        backtrack(nums,onPath);
        return res;
    }
    void backtrack(vector<int> &nums, vector<int> &onPath){
        if(onPath.size()==nums.size()){
            res.push_back(onPath);
            return;
        }
        for(int i=0;i<nums.size();i++){
            // 剪枝，由于有相同的数字，为了不重复，就需要保证相同的数的相对顺序
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
            continue;
            }
            visited[i] = true;
            onPath.push_back(nums[i]);
            backtrack(nums,onPath);
            onPath.pop_back();
            visited[i] = false;
        }
        return;
        
    }
};