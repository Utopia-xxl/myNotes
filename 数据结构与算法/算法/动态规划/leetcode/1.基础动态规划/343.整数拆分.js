/**
 * @param {number} n
 * @return {number}
 */
 //  dp[i] 表示将正整数 i 拆分成至少两个正整数的和之后，这些正整数的最大乘积。
//将 i 拆分成 j 和 i-j 的和，且 i-j 不再拆分成多个正整数，此时的乘积是 j×(i−j)；
//将 i 拆分成 j 和 i−j 的和，且 i−j 继续拆分成多个正整数，此时的乘积是 j×dp[i−j]。

var integerBreak = function(n) {
    const dp = new Array(n+1).fill(0);
    for(let i=2;i<=n;i++){
        let curmax=0;
        for(let j=1;j<i;j++){
            curmax = Math.max(Math.max(j*dp[i-j],(i-j)*j),curmax);
        }
        dp[i] = curmax;
    }
    return dp[n];
};