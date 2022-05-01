/**
 * @param {number} n
 * @return {number}
 */
 // f(n) = f(n-1) + f(n-2)
 // 每次只能1或2步，所以到达n的可能性是走一步到的+走两步到的
var climbStairs = function(n) {
    if(n<=3) return n;
    let nextone = 1,nexttwo = 2;
    for(let i=3;i<=n;i++){
        cnt = nextone+nexttwo;
        nextone = nexttwo;
        nexttwo = cnt;
    }
    return cnt;
};