class Solution {
public:
    // 求最短路径,因此只能用BFS不能用DFS
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        if(grid[0][0]==1||grid[m-1][n-1]) return -1;
        // 可选的八个方向
        vector<vector<int>> direction{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        int step=0;
        while(!que.empty()){
            int queLen = que.size();
            step++;
            for(int i=0;i<queLen;i++){
                pair<int,int> tempPosition = que.front();
                que.pop();
                int x = tempPosition.first,y=tempPosition.second;
                if(x==m-1&&y==n-1){
                    // 找到了出口
                    return step;
                }
                for(int j=0;j<8;j++){
                    // 分别将该点8个方向的合法位置加入到队列中
                    int newX = x+direction[j][0],newY = y+direction[j][1];
                    if(newX>=0&&newY>=0&&newX<m&&newY<n&&grid[newX][newY]==0){
                        // 合法位置
                        que.push(make_pair(newX,newY));
                        grid[newX][newY] = 1;
                    }
                }
            }
        }
        return -1;
    }
};