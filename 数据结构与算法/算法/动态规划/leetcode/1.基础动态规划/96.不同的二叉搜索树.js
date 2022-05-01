/**
 * @param {number} n
 * @return {number}
 */
// 首先，分析可能的情况，n个节点都有可能作为头节点
// dp[i] 表示i个节点可能有多少种可能到情况
var numTrees = function(n) {
    const dp = new Array(n+1).fill(0);
    dp[0] = 1;
    for(let i=1;i<=n;i++){
        // 从 3 开始推
        let cnt = 0;
        for(let j=1;j<=i;j++){
            // 从 1 到 i 分别为根节点 共有多少种可能到情况
            cnt += dp[j-1] * dp[i-j];
        }
        dp[i] = cnt;
    }
    return dp[n];
};