class Solution {
public:
    vector<int> onPath;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,k,1);
        return res;
    }
    void backtrack(int n,int k,int start){
        if(onPath.size()==k){
            // 子集的个数为k的就是组合
            res.push_back(onPath);
            return;
        }
        for(int i=start;i<=n;i++){
            onPath.push_back(i);
            backtrack(n,k,i+1);
            onPath.pop_back();
        }
        return;
    }
};