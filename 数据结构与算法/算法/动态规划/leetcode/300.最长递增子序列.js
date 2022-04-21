/**
 * @param {number[]} nums
 * @return {number}
 */

/**
无序列表最关键的一句在于： 数组 d[i]表示长度为 i 的最长上升子序列的末尾元素的最小值，即在数组 1,2,3,4,5,6中长度为3的上升子序列可以为 1,2,3也可以为 2,3,4等等但是d[3]=3，即子序列末尾元素最小为3。

无序列表解释清了数组d的含义之后，我们接着需要证明数组d具有单调性，即证明i<j时，d[i]<d[j]，使用反证法，假设存在k<j时，d[k]>d[j]，但在长度为j，末尾元素为d[j]的子序列A中，将后j-i个元素减掉，可以得到一个长度为i的子序列B，其末尾元素t1必然小于d[j]（因为在子序列A中，t1的位置上在d[j]的后面），而我们假设数组d必须符合表示长度为 i 的最长上升子序列的末尾元素的最小值，此时长度为i的子序列的末尾元素t1<d[j]<d[k]，即t1<d[k]，所以d[k]不是最小的，与题设相矛盾，因此可以证明其单调性

无序列表证明单调性有两个好处：1.可以使用二分法；2.数组d的长度即为最长子序列的长度；
 */
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

// 动态规划
// var lengthOfLIS = function(nums) {
//     // 最小长度是自己本身，也就是1 
//     const dp = new Array(nums.length).fill(1);
//     for(let i=0;i<nums.length;i++){
//         for(let j=0;j<i;j++){
//             if(nums[j]<nums[i]){
//                 dp[i] = Math.max(dp[i],dp[j]+1);
//             }
//         }
//     }
//     let res = 1;
//     // 返回最大子序列数，也就是dp数组中的最大值
//     for(const num of dp){
//         res = Math.max(num,res);
//     }
//     return res;
// };