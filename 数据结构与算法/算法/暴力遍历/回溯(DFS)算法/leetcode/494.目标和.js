/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

 let cnt = 0;
 var findTargetSumWays = function(nums, target) {
     if(nums.length===0) return cnt;
     backtract(nums,0,target, 0);
     return cnt;
 };
 
 /**
  */
 
  function backtract(nums, index, target, sum){
      if(index === nums.length){
          if(sum===target){
              cnt++;
          }
      }else {
          // +
            // sum+=nums[index];
            backtract(nums,index+1,target,sum+nums[index]);
            // sum-=nums[index];

            // sum-=nums[index];
            backtract(nums,index+1,target,sum-nums[index]);
            // sum+=nums[index];
      }
      
      return;
  }
  console.log(findTargetSumWays([1,1,1,1,1],3));

 console.log(findTargetSumWays([1],1));