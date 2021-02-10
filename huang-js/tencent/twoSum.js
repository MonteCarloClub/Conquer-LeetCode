/** https://leetcode-cn.com/leetbook/read/tencent/xxqfy5/ */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    // for (let left = 0; left < nums.length; left++) {
    //     const one = nums[left];
    //     for (let right = left + 1; right < nums.length; right++) {
    //         const two = nums[right];
    //         if (one + two === target) {
    //             return [left, right];
    //         }
    //     }
    // }
    numOcc = {}
    for (let index = 0; index < nums.length; index++) {
        const left = nums[index];
        if (numOcc[target - left] != null) {
            return [numOcc[target - left], index]
        }
        numOcc[left] = index;
    }
};

console.log(twoSum(nums = [2, 7, 11, 15], target = 9))
console.log(twoSum(nums = [3, 2, 4], target = 6))
console.log(twoSum(nums = [3, 3], target = 6))