package two_sum

func twoSum(nums []int, target int) []int {
	rank := make(map[int]int, len(nums))
	for i, n := range nums {
		// 查询键(target-n)是否有值。如果有，那么返回答案
		if j, flag := rank[target-n]; flag {
			return []int{j, i} /* i、j是逆序的 */
		}
		// 如果无，插入新键值，等待被查询
		rank[n] = i
	}
	return nil
}
