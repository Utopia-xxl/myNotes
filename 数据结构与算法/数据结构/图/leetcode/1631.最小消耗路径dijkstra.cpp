// 维护节点的状态，辅助算法运行
struct State{
    // 图中节点的id
    int id;
    // 从start节点到当前节点的距离
    int distFromStart;

    State(int id, int distFromStart):id(id),distFromStart(distFromStart){}

};

struct Cmp{
    bool operator()(State& a,State& b){
        return a.distFromStart > b.distFromStart;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 1. build graph
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<vector<int>>> graph(m*n);
        // graph 中的下表代表每个顶点 ,每个顶点保存相邻的节点和权重
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // 每个顶点要向4个方向构建边
                for(int ii=0;ii<4;ii++){
                    int x = i+dir[ii][0];
                    int y = j+dir[ii][1];
                    if(x>=0&&y>=0&&x<m&&y<n){
                        // 节点是合法的
                        graph[i*n+j].push_back({x*n+y,abs(heights[i][j]-heights[x][y])});
                    }
                }
            }
        }
        // 记录最短路径的权重， 你可以理解为 dp table
        // 定义：distTo[i] 的值就是节点start 到达节点i的最短路径权重,求最小值，所以初始化为最大值
        vector<int> distTo(m*n,INT_MAX);
        distTo[0] = 0;

        // 优先队列，distFromStart较小的排在前面
        priority_queue<State,vector<State>,Cmp> pq;
        pq.push({0,0});
        while(!pq.empty()){
            State curState = pq.top();
            pq.pop();
            int curNodeID = curState.id;
            int curDistFromStart = curState.distFromStart;
            if(curDistFromStart>distTo[curNodeID]){
                // 已经有一条更短的路径到达此节点，因此可以直接跳过
                continue;
            }
            if(curNodeID==m*n-1){
                return curDistFromStart;
            }
            // 将curNode 的相邻节点装入队列
            for(vector<int> &neighbor: graph[curNodeID]){
                int nextNodeID = neighbor[0];
                // 看看从 curNode 到 nextNode的距离是否会更短
                int distToNextNode = max(distTo[curNodeID],abs(heights[curNodeID/n][curNodeID%n]-heights[nextNodeID/n][nextNodeID%n]));
                if(distTo[nextNodeID]>distToNextNode){
                    // 更新 dp table
                    distTo[nextNodeID] = distToNextNode;
                    //将这个节点以及距离放入队列
                    pq.push({nextNodeID,distToNextNode});
                }
            }
        }
        return 0;
    }
};