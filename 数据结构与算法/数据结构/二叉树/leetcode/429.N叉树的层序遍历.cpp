/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // 层序遍历需要借助一个队列来辅助实现
        if(root==nullptr) return vector<vector<int>>{};
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
                // if(!tempNode->children.empty()){
                //     for(Node *child:tempNode->children){
                //         que.push(child);
                //     }
                // }
                for(Node *child:tempNode->children){
                    // 加入队列
                    que.push(child);
                }
                hierarchical.push_back(tempNode->val);
            }
            res.push_back(hierarchical);
        }
        return res;
    }
};