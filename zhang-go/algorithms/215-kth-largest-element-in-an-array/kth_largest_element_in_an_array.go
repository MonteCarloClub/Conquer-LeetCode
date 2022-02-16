package kth_largest_element_in_an_array

func findKthLargest(nums []int, k int) int {
	lenOfNums := len(nums)
	buildMaxHeap(nums, 0, lenOfNums)
	for i := 0; i < k-1; i++ {
		nums[0], nums[lenOfNums-i-1] = nums[lenOfNums-i-1], nums[0]
		maxHeapify(nums, 0, lenOfNums-i-1)
	}
	return nums[0]
}

func buildMaxHeap(nums []int, lo int, hi int) {
	for i := (hi - lo) / 2; i >= lo; i-- {
		maxHeapify(nums, i, hi)
	}
}

func maxHeapify(nums []int, lo int, hi int) {
	leftChild, rightChild, max := lo*2+1, lo*2+2, lo
	if leftChild < hi && nums[leftChild] > nums[max] {
		max = leftChild
	}
	if rightChild < hi && nums[rightChild] > nums[max] {
		max = rightChild
	}
	if lo != max {
		nums[lo], nums[max] = nums[max], nums[lo]
		maxHeapify(nums, max, hi)
	}
}
