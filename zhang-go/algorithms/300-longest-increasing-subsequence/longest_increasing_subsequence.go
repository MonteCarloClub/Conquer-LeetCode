package longest_increasing_subsequence

func lengthOfLIS(nums []int) int {
	lenOfLISIncludingThisTrailer := make([]int, len(nums))
	lenOfLISIncludingThisTrailer[0] = 1
	result := 1
	for i := 1; i < len(nums); i++ {
		lenOfLIS := 1
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] && lenOfLISIncludingThisTrailer[j]+1 > lenOfLIS {
				lenOfLIS = lenOfLISIncludingThisTrailer[j] + 1
			}
		}
		lenOfLISIncludingThisTrailer[i] = lenOfLIS
		if lenOfLIS > result {
			result = lenOfLIS
		}
	}
	return result
}
