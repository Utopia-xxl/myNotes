/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * 思路：分别中序遍历两颗二叉搜索树，得到两个有序的数组
 * 利用双指针合并两个数组
 * 时间复杂度 O(n)
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */

 var getAllElements = function(root1, root2) {
    let arr1 = [];
    const arr2 = [];
    const inorder = (root, res) => {
        // if(root===null) return;
        if(root){
            inorder(root.left, res);
            res.push(root.val);
            inorder(root.right, res);
        }

    }
    // 得到两个有序数组
    inorder(root1,arr1);
    inorder(root2,arr2);
    // 双指针合并
    let i=0,j=0,index=0;
    const res = [];
    while(i<arr1.length&&j<arr2.length){
        if(arr1[i]<=arr2[j]){
            res[index++] = arr1[i++];
        }else{
            res[index++] = arr2[j++];
        }
    }
    // 还存在一个数组的值没有放完
    if(i===arr1.length){
        while(j<arr2.length){
            res[index++] = arr2[j++];
        }
    }else{
        while(i<arr1.length){
            res[index++] = arr1[i++];
        }
    }
    return res;
};