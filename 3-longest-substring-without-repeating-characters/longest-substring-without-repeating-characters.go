package longest_substring_without_repeating_characters

func lengthOfLongestSubstring(s string) int {
	// 字符串是空，返回答案
	if s == "" {
		return 0
	}
	// 字符串非空，滑动窗口
	res := 1
	lo, hi := 0, 1 /* 从[0, 1)开始 */
	hashTable := make(map[byte]bool, len(s))
	for {
		// 滑动窗口的右端搜索到重复元素，把左端向右滑动
		if hashTable[s[hi-1]] {
			// 滑动窗口的左端搜索到重复元素，设置终止条件
			if s[lo] == s[hi-1] {
				hashTable[s[hi-1]] = false /* 这样做使下一次循环跳到else */
			}
			hashTable[s[lo]] = false
			lo++
		} else {
			hashTable[s[hi-1]] = true
			// 可能更新答案
			if hi-lo > res {
				res = hi - lo
			}
			// 滑动窗口搜索到末元素，跳出循环
			if hi < len(s) {
				hi++
			} else {
				break
			}
		}
	}
	return res
}
