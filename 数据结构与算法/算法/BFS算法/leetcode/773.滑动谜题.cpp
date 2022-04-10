class Solution {
public:
    string swapxy(string str,int x, int y){
        char temp = str[x];
        str[x] = str[y];
        str[y] = temp;
        return str;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        // 将2 ✖️ 3的数组转换成一维数组
        string changeBoard="";
        string target="123450";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                changeBoard.push_back(board[i][j] + '0');
            }
        }
        // 每次都是0和它上下左右的进行交换
        // 存储0在这6个位置中的交换选择
        vector<vector<int>> exchangeOptions{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        // 防止走回头路，不能使用vector<int>因为默认hash不支持
        unordered_set<string> visited;
        queue<string> que;
        int step=0;
        que.push(changeBoard);
        while(!que.empty()){
            int queLenth = que.size();
            for(int i=0;i<queLenth;i++){
                // 取队首元素
                string cur = que.front();
                que.pop();
                visited.insert(cur);
                if(cur==target){
                    return step;
                }
                for(int i=0;i<6;i++){
                    // 找cur中0所在的位置
                    if(cur[i]=='0'){
                        for(int x:exchangeOptions[i]){
                            string newBoard = swapxy(cur,i,x);
                            if(visited.find(newBoard)==visited.end()){
                                que.push(newBoard);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};