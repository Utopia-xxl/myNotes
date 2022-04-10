# 图的逻辑结构和实现

图是由节点和边构成

![img](pictures/0.jpg)

```c++
struct Vertex{
   int id;
   Vertex* neighbors;
}
```

常见的图通常存储在邻接表和邻接矩阵(数组和链表)

![img](pictures/2-20220406224506212.jpeg)

最后，我们再明确一个图论中特有的**度**（degree）的概念，在无向图中，「度」就是每个节点相连的边的条数。

由于有向图的边有方向，所以有向图中每个节点「度」被细分为**入度**（indegree）和**出度**（outdegree）

# 图的遍历

图的遍历是指从图中的某一个顶点出发，按照某种搜索方法沿着图中的边对图中的所有顶点访问一次且仅访问一次。

图与多叉树的区别在于，图可能是含有环的，因此需要一个visites数组来辅助遍历

主要的算法是BFS和DFS

## DFS

DFS类似数的先序遍历

```java
// 防⽌重复遍历同⼀个节点
boolean[] visited;
// 从节点 s 开始 DFS 遍历，将遍历过的节点标记为 true
void traverse(List<Integer>[] graph, int s) {
 if (visited[s]) {
 return;
 }
 /* 前序遍历代码位置 */
 // 将当前节点标记为已遍历
 visited[s] = true;
 for (int t : graph[s]) {
 traverse(graph, t);
 }
 /* 后序遍历代码位置 */
}
```

## BFS

BFS类似数的层序遍历，多叉树的层序遍历

```C++
queue<Node*> que;
que.push(root);
// 创建一个二维数组存放结果
vector<vector<int>> res;
while(!que.empty()){
// 获取队列元素个数
int queLen = que.size();
// while是每一层的循环
// for是每一层节点的循环
vector<int> hierarchical;
for(int i=0;i<queLen;i++){
// 依次遍历每个子节点，如果子节点有孩子节点就依此入队
  Node* tempNode = que.front();
  que.pop();
  for(Node *child:tempNode->children){
      // 加入队列
      que.push(child);
  }
  hierarchical.push_back(tempNode->val);
}
   res.push_back(hierarchical);
}

```



# 拓扑排序

本⽂就结合具体的算法题，来说两个图论算法：**有向图的环检测、拓扑排序算法**这两个问题既可以用DFS也可以用BFS解决

## 环检测算法DFS

![image-20220409173619154](pictures/image-20220409173619154.png)

利用回溯算法的思想，记录一个onPath如果路径有重复的，那么说明有环

在进⼊节点 s 的时候将 onPath[s] 标记为 true，离开时标记回 false，如果 发现 onPath[s] 已经被标记，说明出现了环。

```java
    void traverse(vector<vector<int>> &graph,int s){
        if(onPath[s]){
            // 发现环,路径上如果有相同的节点
            hasCycle = true;
        }
        if(visited[s]||hasCycle){
            return;
        }
        // 类似回溯算法的做法
        visited[s] = true; // node是否被访问过
        onPath[s] = true;  // 路径上已有的节点
        for(int node:graph[s]){
            traverse(graph, node);
        }
        onPath[s] = false;
    }
```

## 环检测算法BFS



## 拓扑排序算法DFS

拓扑排序定义：对一个**有向无环图**G进行拓扑排序，是将G中所有顶点排成一个线性序列，使得图中任意一个顶点u和v，若存在由u到v的路径，则拓扑排序中u出现在v的前面

![image-20220409221433411](pictures/image-20220409221433411.png)

对于代码实现而言，**拓扑排序首先要判断图不带环，然后就是后序遍历图的结果然后反转，就是拓扑排序的结果**

因此我们只需要在环检测DFS的基础上在后序遍历部分加上对每个节点的记录，然后进行反转就行了。