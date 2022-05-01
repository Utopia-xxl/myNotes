/**
 * @param {number[][]} matrix
 * @return {number}
 */

 const memo = new Array();

 var minFallingPathSum = function(matrix) {
     let m = matrix.length,n = matrix[0].length;
     for(let i=0;i<m;i++){
         memo[i] = new Array(n).fill(101);
     }
     let res = 101;
     console.log(res);
     for(let i=0;i<n;i++){
         // 第一行的任一元素开始
         memo[0][i] = matrix[0][i];
         res = Math.min(dp(matrix,0,i),res);
         console.log(memo)
     }
     return res;
 };
 function dp(matrix,x,y){
     if(x==matrix.length-1){
         return matrix[x][y];
     }
     if(x<0||y<0||y>=matrix[0].length){
         // 不合法位置
         return Number.MAX_VALUE;
     }
     if(x>0&&memo[x][y]!=101){
         // 返回备忘录的记录，避免重复计算
         return memo[x][y];
     }
     memo[x][y] = Math.min(dp(matrix,x+1,y-1),dp(matrix,x+1,y),dp(matrix,x+1,y+1))+matrix[x][y];
     return memo[x][y];
 }
 console.log(minFallingPathSum([[2,1,3],[6,5,4],[7,8,9]]));