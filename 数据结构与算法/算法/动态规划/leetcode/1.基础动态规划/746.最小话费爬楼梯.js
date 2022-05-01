/**
 * @param {number[]} cost
 * @return {number}
 */
 var minCostClimbingStairs = function(cost) {
    const n = cost.length;
    // dp表示到下标为i的台阶的最小花费
    const dp = new Array(n+1).fill(Number.MAX_VALUE);
    dp[0] = 0;
    dp[1] = 0;
    // 顶点下标为 i+1
    for(let i=2;i<=n;i++){
        dp[i] = Math.min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    // 倒数第一和倒数第二个台阶都能到达顶部
    return dp[n];
};

// var minCostClimbingStairs = function(cost) {
//     const n = cost.length;
//     // dp表示从下标为i的台阶向上爬的最小花费
//     const dp = new Array(n).fill(Number.MAX_VALUE);
//     dp[0] = cost[0];
//     dp[1] = cost[1];
//     for(let i=2;i<n;i++){
//         dp[i] = Math.min(dp[i-1],dp[i-2])+cost[i];
//     }
//     // 倒数第一和倒数第二个台阶都能到达顶部
//     return Math.min(dp[n-1],dp[n-2]);
// };