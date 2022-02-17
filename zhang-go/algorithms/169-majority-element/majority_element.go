package majority_element

func majorityElement(nums []int) int {
	var candidate, count int
	countOfElem := map[int]int{}
	for _, elem := range nums {
		countOfElem[elem]++
		if countOfElem[elem] > count {
			candidate = elem
			count = countOfElem[elem]
		}
	}
	return candidate
}
