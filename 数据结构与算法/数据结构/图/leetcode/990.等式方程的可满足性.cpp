class Solution {
public:
    int find(int x){
        // 根节点的parent[x] == x
        while (parent[x]!=x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void Union(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;
        // 将两棵树合并为1棵
        parent[rootP] = rootQ;
    }
    vector<int> parent;
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        // UF初始化
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        // 是否可满足取决于  =  和  !  是否有冲突
        // 按==关系构建uf，如果出现不满足！返回false
        for(string str:equations){
            if(str[1]=='='){
                Union(str[0]-'a',str[3]-'a');
            }
        }
        for(string str:equations){
            if(str[1]=='!'){
                if(find(str[0]-'a')==find(str[3]-'a')){
                    return false;
                }
            }
        }
        
        return true;
    }
};