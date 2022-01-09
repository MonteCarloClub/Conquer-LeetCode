package threesum

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	if len(nums) < 3 {
		return nil
	}
	results := [][]int{}
	lenOfnums := len(nums)
	sort.Ints(nums)
	for i := 0; i < lenOfnums-2; i++ {
		if nums[i] > 0 || i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < lenOfnums-1; j++ {
			if nums[i]+nums[j] > 0 || j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			if nums[i]+nums[j]+nums[j+1] > 0 ||
				nums[i]+nums[j]+nums[lenOfnums-1] < 0 {
				continue
			}
			for k := lenOfnums - 1; k > j; k-- {
				if nums[i]+nums[j]+nums[k] == 0 {
					results = append(results, []int{nums[i], nums[j], nums[k]})
					break
				}
			}
		}
	}
	return results
}
