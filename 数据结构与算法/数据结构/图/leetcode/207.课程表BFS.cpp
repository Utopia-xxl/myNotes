// BFS判断是否有环的思路：

// 1. 构建邻接表，边的方向表示 被依赖 关系
// 2. 构建一个indegree数组记录每个节点的入度，即indegree[i]记录节点i的入度
// 3. 对BFS队列进行初始化，将入度为0的节点首先装入队列
// 4. 开始执行BFS循环，不断弹出队列中的节点，减少相邻节点的入度，并将入度为0的节点加入队列
// 5. 如果最终所有节点都被遍历过，则说明不存在环，负责 **存在剩下节点组成的环**
class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        // 判断是否有循环引用的情况，即可说明是否可以完成
        // 根据数据生成Graph然后判断是否存在环
        
        // 1. 构建图
        vector<vector<int>> graph = buildGraph(numCourses,prerequisites);

        // 2. 构建入度数组
        vector<int> indgree(numCourses,0);
        for(vector<int> edge:prerequisites){
            indgree[edge[0]]++;
        }
        // 3. 判断是否有环(BFS)
        queue<int> que;
        // 初始化，将度为0的节点入队
        for(int i=0;i<numCourses;i++){
            if(indgree[i] == 0){
                // 节点i没有入度，即没有依赖的节点
                // 可以作为拓扑排序的起点，加入队列
                que.push(i);
            }
        }
        int count = 0; // 记录遍历的节点数
        // 标准度BFS模版
        while(!que.empty()){
            // 弹出节点 cur，并将它指向的节点的入度减一
            int cur = que.front();
            que.pop();
            count++;
            for(int node : graph[cur]){
                indgree[node]--;
                if(indgree[node]==0){
                    // 如果入度为0，说明node已经没有依赖
                    que.push(node);
                }
            }
        }
        // 如果所有节点都被遍历过则表示，没有换
        return count==numCourses;

        
    }
    
    vector<vector<int> > buildGraph(int numCourses,vector<vector<int> >& prerequisites){
        // 将图存储为临界表
        vector<vector<int> > graph(numCourses);
        // 初始化graph
        for(int i=0;i<numCourses;++i){
            graph[i] = vector<int> {};
        }
        for(auto edge : prerequisites){
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
};