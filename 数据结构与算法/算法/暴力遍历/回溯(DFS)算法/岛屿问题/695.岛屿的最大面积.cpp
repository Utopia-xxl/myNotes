class Solution {
public:
    int maxArea=0;
    int Area=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    Area=0;
                    backtrack(grid,i,j);
                    maxArea = max(Area,maxArea);
                }
            }
        }
        return maxArea;
    }
    void backtrack(vector<vector<int>>& grid, int x, int y){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) return;
        if(grid[x][y]==0) return;
        // 分别向上下左右遍历
        grid[x][y]=0;
        Area++;
        backtrack(grid,x+1,y);
        backtrack(grid,x,y+1);
        backtrack(grid,x-1,y);
        backtrack(grid,x,y-1);
        return;
    }
};