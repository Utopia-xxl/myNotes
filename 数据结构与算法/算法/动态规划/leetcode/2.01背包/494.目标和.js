/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 var findTargetSumWays = function(nums, target) {
    //(sum−neg)−neg=sum−2*neg=target  sum-neg 就是正数的集合
    // 由上面的公式可以推出 neg = (sum - target) / 2 ;
    // dp[neg] 有多少种方案
    // 排除不可能的情况
    const n = nums.length;
    const sum = nums.reduce((pre,cur)=> pre+cur);
    if((sum-target)%2===1){
        return 0;
    }
    if(sum-target<0){
        return 0;
    }
    const neg = (sum-target)/2;  //必定能整除
    const dp = new Array(neg+1).fill(0);
    dp[0] = 1;
    // !!! 初始化 dp[0] = 1, 为0的可能性只有什么都没有这一种
    for(let i=0;i<n;i++){
        for(let j=neg;j>=nums[i];j--){
            dp[j] += dp[j-nums[i]]; 
        }
    }
    return dp[neg];
};