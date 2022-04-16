class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);  // 0表示未访问，1，2代表两种颜色
        queue<int> q; // BFS辅助队列
        for(int i=0;i<n;i++){
            // 遍历所有节点，可能存在多个连通分量的情况
            if(!color[i]){
                q.push(i);
                color[i] = 1; // 初始情况，图的第一个节点给默认的颜色1
            }
            while(!q.empty()){
                int index = q.front();
                // 访问队列中的元素，没染色的将相邻的染上不同的颜色
                // 颜色的判断是否颜色相同
                q.pop();
                for(int neighbor:graph[index]){
                    if(!color[neighbor]){
                        q.push(neighbor);
                        // 染上不同的颜色
                        color[neighbor] = 3 - color[index];
                    }else if(color[neighbor]==color[index]){
                        // 如果相邻的节点颜色一样，则不能被二分
                        return false;
                    }
                }
            }
        }
        return true;
    }
};