package leetcode

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {

}

/*
 * 返回2个整型数的较小值
 */
func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}

/*
 * 返回2个整型数的较大值
 */
func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}

/*
 * nums1、nums2的排序器
 * 参数表：2个数组和它们的长度
 * 排序的目标是使二分落在n1的元素后
 */
func arrSorter(nums1 []int, nums2 []int, len1 int, len2 int) (n1 []int, n2 []int) {
	if len1 < len2 || len1 == len2 && nums2[len2-1] <= nums1[0] {
		return nums2, nums1
	}
	return nums1, nums2
}

/*
 * 判断这个二分是否搜索到中位数
 * 参数表：(n1, n2)是(nums1, nums2)的某种排列，r是这个二分在n1较大的秩，l1、l2分别是n1、n2的长度
 * n1的长度大于等于n2的，如果它们长度相等，那么二分不落在n1的首元素前，这样r∈(0, l1]
 */
func isMedian(n1 []int, n2 []int, r int, l1 int, l2 int) bool {
	var maxOfLo, minOfHi, minOfHi1, minOfHi2 int
	if r == (l1+l2)>>1 {
		maxOfLo = n1[r-1]
	} else {
		maxOfLo = max(n1[r-1], n2[((l1+l2)>>1)-r-1])
	}
	// 2个数组的长度和是偶数
	if (l1+l2)%2 == 0 {
		if r == l1 {
			minOfHi = n2[((l1+l2)>>1)-r]
		} else {
			minOfHi = min(n1[r], n2[((l1+l2)>>1)-r])
		}
		return maxOfLo <= minOfHi
	}
	// 2个数组的长度和是奇数
	if r == l1-1 {
		minOfHi1 = n2[((l1+l2)>>1)-r]
	} else {
		minOfHi1 = min(n1[r+1], n2[((l1+l2)>>1)-r])
	}

}
