package diao_zheng_shu_zu_shun_xu_shi_qi_shu_wei_yu_ou_shu_qian_mian

func exchange(nums []int) []int {
	lo, hi := 0, len(nums)-1
	for lo < hi {
		for nums[lo]&1 == 1 /* 奇数 */ {
			lo++
			if lo == len(nums) {
				return nums
			}
		}
		for nums[hi]&1 == 0 /* 偶数 */ {
			hi--
			if hi == -1 {
				return nums
			}
		}
		if lo < hi {
			nums[lo] = nums[lo] ^ nums[hi]
			nums[hi] = nums[lo] ^ nums[hi]
			nums[lo] = nums[lo] ^ nums[hi]
		}
	}
	return nums
}
