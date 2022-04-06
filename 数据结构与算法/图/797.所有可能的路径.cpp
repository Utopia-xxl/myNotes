class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> track;
        // 从0开始
        track.push_back(0);
        backtrack(graph,track);
        return res;
    }
    void backtrack(vector<vector<int>> &graph,vector<int> &track){
        // 到了最后一个节点，说明是一个完整的路线，添加到输出
        if(track.back()==graph.size()-1){
                res.push_back(track);
                return;
            }
        for(int i=0;i<graph[track.back()].size();i++){
            // 题目说明是有向无环图，不用考虑会重复
            track.push_back(graph[track.back()][i]);
            backtrack(graph,track);
            track.pop_back();

        }
        return;
    }

};