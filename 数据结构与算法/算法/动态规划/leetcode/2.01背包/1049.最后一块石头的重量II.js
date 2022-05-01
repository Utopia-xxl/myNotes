/**
 * @param {number[]} stones
 * @return {number}
 */
// 贪心，能过90%的用例, 局部最优不能保证最终最优

// 与416. 分割等和子集类似，尽可能均匀分两堆，最后剩下的 

var lastStoneWeightII = function(stones) {
    // 1.求和
    const n = stones.length;  // 石头的个数
    const sum = stones.reduce((pre,cur)=> pre+cur);
    const bagWeight = Math.floor(sum / 2);
    const dp = new Array(bagWeight+1).fill(0);
    for(let i=0;i<n;i++){
        for(let j=bagWeight;j>=stones[i];j--){
            dp[j] = Math.max(dp[j],dp[j-stones[i]]+stones[i]);
        }
        
    }
    return sum - dp[bagWeight] - dp[bagWeight];
};


/**
var lastStoneWeightII = function(stones) {
    stones.sort((a,b)=>a-b);
    const insertToArr = (arr,val) => {
        let i=0
        for(;i<arr.length;i++){
            if(arr[i]>=val){
                break;
            }
        }
        arr.splice(i, 0, val);

    }
    while(stones.length>1){
        // 有序数组 num1 >= num2
        const num1 = stones.pop();
        const num2 = stones.pop();
        if(num1===num2) {
            continue;
        }else{
            insertToArr(stones,num1-num2);
        }
    }
    if(stones.length===1){
        return stones[0];
    }
    return 0;
};
 */