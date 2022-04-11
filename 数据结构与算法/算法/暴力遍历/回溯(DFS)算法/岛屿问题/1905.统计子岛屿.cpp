class Solution {
public:
    bool flge = false;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1){
                    flge=true;
                    backtrack(grid1,grid2,i,j);
                    if(flge){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    void backtrack(vector<vector<int>>& grid1,vector<vector<int>>& grid2, int x, int y){
        if(x<0||y<0||x>=grid2.size()||y>=grid2[0].size()) return;
        if(grid2[x][y]==0) return;
        if(grid1[x][y]==0){
            flge = false;
        }
        
        // 分别向上下左右遍历
        grid2[x][y]=0;
        backtrack(grid1,grid2,x+1,y);
        backtrack(grid1,grid2,x,y+1);
        backtrack(grid1,grid2,x-1,y);
        backtrack(grid1,grid2,x,y-1);
        return ;
    }
};