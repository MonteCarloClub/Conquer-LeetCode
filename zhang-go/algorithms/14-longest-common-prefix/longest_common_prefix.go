package longest_common_prefix

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	result := strs[0]
	for i := 1; i < len(strs); i++ {
		result = findLongestPrefix(result, strs[i])
	}
	return result
}

func findLongestPrefix(str1 string, str2 string) string {
	lenOfPrefixMax := min(len(str1), len(str2))
	lenOfPrefix := 0
	for lenOfPrefix < lenOfPrefixMax && str1[lenOfPrefix] == str2[lenOfPrefix] {
		lenOfPrefix++
	}
	return str1[:lenOfPrefix]
}

func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
