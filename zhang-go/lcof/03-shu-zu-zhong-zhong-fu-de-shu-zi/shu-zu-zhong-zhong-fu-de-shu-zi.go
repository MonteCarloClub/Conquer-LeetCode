package shu_zu_zhong_zhong_fu_de_shu_zi

func findRepeatNumber(nums []int) int {
	hashTable := make([]bool, len(nums))
	for _, elem := range nums {
		if hashTable[elem] {
			return elem
		}
		hashTable[elem] = true
	}
	return -1
}
