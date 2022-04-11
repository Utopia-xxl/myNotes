class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 排除一些情况
        if(k>nums.size()) return false;
        int sum = 0;
        for(int v:nums){
            sum+=v;
        }
        if(sum%k!=0) return false;

        // k个桶（集合），记录每个桶的数字之和
        vector<int> bucket(k,0); //记录每个桶的数字和
        int target = sum/k;
        vector<bool> visited(nums.size(),false);
        // 穷举，看sums是否能被划分成为k个和为target的子集
        sort(nums.begin(), nums.end(), greater<int>());   //可以更快的装满通，使递归次数降低

        return backtrack(k,0,nums,0,visited,target);
    }
    //现在 k 号桶正在思考是否应该把 nums[start] 这个元素装进来；⽬前 k 号桶⾥⾯已经装的数字之和为bucket；used 标志某⼀个元素是否已经被装到桶中；target 是每个桶需要达成的⽬标和。
    bool backtrack(int k,int bucket,vector<int> &nums,int start, vector<bool> &visited,int target){
        if(k==0){
            // 所有桶都满了，而且nums也一定全部用完了
            return true;
        }
        if(bucket==target){
            // 装满了当前桶，递归穷举下一个桶的选择
            return backtrack(k-1,0,nums,0,visited,target);
        }
        // 穷举每个nums[index]可能装入的桶
        for(int i=start;i<nums.size();i++){
            if(visited[i]){
                // 已经装在别的集合里了
                continue;
            }
            if(bucket+nums[i]>target){
                // 装满了，剪枝
                continue;
            }
            // 将nums[index]装入bucket[i]
            visited[i] = true;
            bucket+=nums[i];
            // 穷举下一个数字的选择
            if(backtrack(k,bucket,nums,i+1,visited,target)){
                return true;
            }
            // 撤销选择
            bucket -= nums[i];
            visited[i] = false;
            if(bucket==0) return false; // 没有装入任何元素
        }
        // nums[index] 装入哪个桶都不行
        return false;
    }
};

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         // 排除一些情况
//         if(k>nums.size()) return false;
//         int sum = 0;
//         for(int v:nums){
//             sum+=v;
//         }
//         if(sum%k!=0) return false;

//         // k个桶（集合），记录每个桶的数字之和
//         vector<int> bucket(k,0); //记录每个桶的数字和
//         int target = sum/k;
//         sort(nums.begin(),nums.end(),greater<int>());

//         // 穷举，看sums是否能被划分成为k个和为target的子集
//         return backtrack(nums,0,bucket,target);
//     }
//     bool backtrack(vector<int> &nums,int index, vector<int> &bucket,int target){
//         if(index == nums.size()){
//             // 所有的数字都放完了，检查是否每个桶的数字之和都是target
//             for(int i=0;i<bucket.size();i++){
//                 if(bucket[i] != target){
//                     return false;
//                 }
//             }
//             return true;
//         }
//         // 穷举每个nums[index]可能装入的桶
//         for(int i=0;i<bucket.size();i++){
//             if(bucket[i]+nums[index]>target){
//                 // 装满了，剪值
//                 continue;
//             }
//             // 将nums[index]装入bucket[i]
            
//             bucket[i]+=nums[index];
//             // 穷举下一个数字的选择
//             if(backtrack(nums,index+1,bucket,target)){
//                 return true;
//             }
//             // 撤销选择
//             bucket[i] -= nums[index];
//             if(bucket[i]==0) return false;
//         }
//         // nums[index] 装入哪个桶都不行
//         return false;
//     }
// };