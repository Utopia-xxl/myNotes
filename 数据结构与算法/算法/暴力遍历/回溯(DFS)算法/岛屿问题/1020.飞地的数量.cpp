class Solution {
public:
    int cnt=0;
    int numEnclaves(vector<vector<int>>& grid) {
        // 先将边界的岛屿淹掉
        for(int i=0; i<grid.size();i++){
            backtrack(grid,i,0);
            backtrack(grid,i,grid[0].size()-1);
        }
        for(int i=0;i<grid[0].size();i++){
            backtrack(grid,0,i);
            backtrack(grid,grid.size()-1,i);
        }
        cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    backtrack(grid,i,j);
                }
            }
        }
        return cnt;
    }
    void backtrack(vector<vector<int>>& grid, int x, int y){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) return;
        if(grid[x][y]==0) return;
        // 分别向上下左右遍历
        grid[x][y]=0;
        cnt++;
        backtrack(grid,x+1,y);
        backtrack(grid,x,y+1);
        backtrack(grid,x-1,y);
        backtrack(grid,x,y-1);
        return;
    }
};