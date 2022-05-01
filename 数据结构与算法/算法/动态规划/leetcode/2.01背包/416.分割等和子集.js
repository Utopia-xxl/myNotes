/**
 * @param {number[]} nums
 * @return {boolean}
 */
// 二维dp版本，可优化至一维
var canPartition = function(nums) {
    const n = nums.length;
    // 1.求和/2为每个集合到大小
    let sum = 0;
    for(const val of nums){
        sum+=val;
    }
    if(sum%2!==0){
        return false;
    }else{
        // 计算背包的容量
        sum = Math.floor(sum/2);
    }
    const dp = new Array(sum+1).fill(0);
    // 初始化dp
    for(let i=0;i<n;i++){ // 物品个数
        for(let j=sum;j>=nums[i];j--){ // 背包容量
            // 从后往前，避免重复计算物品
            dp[j] = Math.max(dp[j],dp[j-nums[i]]+nums[i]); 
        }
    }
    return dp[sum]===sum?true:false;
};


/**
var canPartition = function(nums) {
    const n = nums.length;
    // 1.求和/2为每个集合到大小
    let sum = 0;
    for(const val of nums){
        sum+=val;
    }
    if(sum%2!==0){
        return false;
    }else{
        // 计算背包的容量
        sum = Math.floor(sum/2);
    }
    const dp = new Array(n).fill(0).map(()=>new Array(sum+1).fill(-1));
    for(let i=0;i<n;i++){
        dp[i][0] = 0;
    }
    // 初始化dp
    for(let i=1;i<=sum;i++){
        if(i>=nums[0]){
            dp[0][i] = nums[0];
        }
    }

    for(let i=1;i<n;i++){ // 物品个数
        for(let j=1;j<=sum;j++){ // 背包容量
            if(j<nums[i]) dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = Math.max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]); 
        }
    }
    return dp[n-1][sum]===sum?true:false;
};
 */