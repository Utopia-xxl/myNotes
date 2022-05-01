/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
 var uniquePathsWithObstacles = function(obstacleGrid) {
    const m = obstacleGrid.length,n = obstacleGrid[0].length;
    if(obstacleGrid[0][0]===1||obstacleGrid[m-1][n-1]===1) return 0;
    if(m==1&&n==1) return 1;
    const dp = new Array(m).fill(0).map(() => new Array(n).fill(0));
    for(let i=1;i<m;i++){
        if(obstacleGrid[i][0]===0){
            dp[i][0] = 1;
        }else{
            break;
        }
    }
    for(let i=1;i<n;i++){
        if(obstacleGrid[0][i]===0){
            dp[0][i] = 1;
        }else{
            break;
        }
    }
    for(let i=1;i<m;i++){
        for(let j=1;j<n;j++){
            if(obstacleGrid[i][j]===1){
                dp[i][j] = 0;
            }else
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
};