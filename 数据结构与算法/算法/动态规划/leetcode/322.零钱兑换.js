/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
 var coinChange = function(coins, amount) {
    const dptable = new Array(amount+1).fill(amount+1);
    dptable[0] = 0;
    console.log(dptable[11]);
    dp(coins,amount,dptable);
    return dptable[amount]===amount+1?-1:dptable[amount];
};
function dp(coins,amount,dptable){
    // 排除不合法情况
    for(let i=0;i<=amount;i++){
        for(const coin of coins){
            if(i-coin<0) continue;
            dptable[i] = Math.min(dptable[i], (dptable[i-coin] + 1));
        }
    }
}