/** https://leetcode-cn.com/leetbook/read/tencent/xx6c46/ */

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    // nums = [...nums1, ...nums2]
    // nums.sort((a, b) => a - b)
    // let mid = parseInt(nums.length / 2);
    // if(nums.length % 2) return nums[mid]
    // return (nums[mid - 1] + nums[mid]) / 2
    let min1 = 0, max1 = nums1.length - 1;
    let min2 = 0, max2 = nums2.length - 1;
    while (min1 < max1 && min2 < max2) {
        nums1[min1] < nums2[min2] ? min1 += 1 : min2 += 1;
        nums1[max1] > nums2[max2] ? max1 -= 1 : max2 -= 1;
    }

    if (nums1[max1] < nums2[min2])
        var nums = [...nums1.slice(min1, max1 + 1), ...nums2.slice(min2, max2 + 1)]
    else
        var nums = [...nums2.slice(min2, max2 + 1), ...nums1.slice(min1, max1 + 1)]

    nums.sort((a, b) => a - b)
    let mid = parseInt(nums.length / 2);
    if(nums.length % 2) return nums[mid]
    return (nums[mid - 1] + nums[mid]) / 2  
};

console.log(findMedianSortedArrays(nums1 = [0, 0], nums2 = [0, 0]))
console.log(findMedianSortedArrays(nums1 = [], nums2 = [1]))
console.log(findMedianSortedArrays(nums1 = [2], nums2 = []))
console.log(findMedianSortedArrays(nums1 = [2], nums2 = [1, 3]))
console.log(findMedianSortedArrays(nums1 = [1, 2, 3, 4], nums2 = [5, 6, 7, 8, 9, 10]))