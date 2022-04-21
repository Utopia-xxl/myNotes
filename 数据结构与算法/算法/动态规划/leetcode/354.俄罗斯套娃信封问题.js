/**
 * @param {number[][]} envelopes
 * @return {number}
 */
 var maxEnvelopes = function(envelopes) {
    // 对w进行升序排列，而h只能是降序排列，两个w相同的信封不能装在一起
    // 所以就要排除 w 相同时的递增情况
    envelopes.sort((a,b)=>a[0]===b[0]?b[1]-a[1]:a[0]-b[0]);
    return lengthOfLIS(envelopes.map(a=>a[1]));
    
};
 // 贪心 + 二分
 var lengthOfLIS = function(nums) {
    const d = new Array(nums.length+1).fill(0);
    let len = 1;
    d[len] = nums[0];
    for(let i = 1; i<nums.length;i++){
        if(nums[i]>d[len]){
            d[++len] = nums[i];
        }else{
            // 采取二分查找合适的位置
            let l=1,r=len,pos=0;
            while(l<=r){
                let mid = Math.floor((l+r)/2);
                if(nums[i]>d[mid]){
                    pos = mid;
                    l = mid+1;
                }else{
                    r = mid - 1;
                } 
            }
            d[pos+1] = nums[i];
        }
    }
    return len;
};