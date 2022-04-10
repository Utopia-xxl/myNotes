class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    vector<int> postOrder;
    bool hasCycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        // 判断是否有循环引用的情况，即可说明是否可以完成
        // 根据数据生成Graph然后判断是否存在环
        
        // 1. 构建图
        vector<vector<int>> graph = buildGraph(numCourses,prerequisites);
        // 2. 判断是否有环
        visited.resize(numCourses);
        onPath.resize(numCourses);
        for(int i=0;i<numCourses;i++){
            // 因为图中可能存在孤立的点
            traverse(graph,i);
        }
        if(hasCycle){
            return vector<int>{};
        }
        reverse(postOrder.begin(),postOrder.end());
        return postOrder;
    }
    
    void traverse(vector<vector<int>> &graph,int s){
        if(onPath[s]){
            // 发现环,路径上如果有相同的节点
            hasCycle = true;
        }
        if(visited[s]||hasCycle){
            return;
        }
        // 类似回溯算法的做法
        visited[s] = true;
        onPath[s] = true;
        for(int node:graph[s]){
            traverse(graph, node);
        }
        onPath[s] = false;
        postOrder.push_back(s);
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