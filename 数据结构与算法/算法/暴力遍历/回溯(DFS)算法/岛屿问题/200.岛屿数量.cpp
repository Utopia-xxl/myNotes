class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    backtrack(grid,i,j);
                }
            }
        }
        return cnt;
    }
    void backtrack(vector<vector<char>>& grid, int x, int y){
        if(x<0||y<0||x>grid.size()-1||y>grid[0].size()-1||grid[x][y]=='0') return;
        // 分别向上下左右遍历
        grid[x][y]='0';
        backtrack(grid,x+1,y);
        backtrack(grid,x,y+1);
        backtrack(grid,x-1,y);
        backtrack(grid,x,y-1);
        return;
    }
};