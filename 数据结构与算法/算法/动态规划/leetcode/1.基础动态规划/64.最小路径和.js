/**
 * 如果不规定只能向下或者向右移动一步，不然的话就是迪杰斯特拉的最短路径问题
 * @param {number[][]} grid
 * @return {number}
 */

 // 备忘录，避免重复计算 ，自顶向下
 var memo = new Array();
 var minPathSum = function(grid) {
     let m = grid.length, n = grid[0].length;
     for(let i=0;i<m;i++){
         memo[i] = new Array(n).fill(-1);
     }
     return dp(grid,m-1,n-1);
 };
 
 function dp(grid,x,y){
     if(x==0&&y==0) return grid[0][0];
     if(x<0||y<0){
         return Number.MAX_VALUE;
     }
     if(memo[x][y] !== -1){
         return memo[x][y];
     }
     memo[x][y] = Math.min(dp(grid,x-1,y),dp(grid,x,y-1)) + grid[x][y];
     return memo[x][y];
 }

 // 自底向上
 var minPathSum = function(grid) {
    let m = grid.length, n = grid[0].length;
    const memo = new Array(m).fill(0).map(()=>new Array(n).fill(-1));
    memo[0][0] = grid[0][0];
    for(let i = 1;i<m;i++){
        memo[i][0] = memo[i-1][0]+grid[i][0];
    }
    for(let i = 1;i<n;i++){
        memo[0][i] = memo[0][i-1] + grid[0][i];
    }
    // 状态转移
    for(let i=1;i<m;i++){
        for(let j=1;j<n;j++){
            memo[i][j] = Math.min(memo[i-1][j],memo[i][j-1])+grid[i][j];
        }
    }
    return memo[m-1][n-1];
};
