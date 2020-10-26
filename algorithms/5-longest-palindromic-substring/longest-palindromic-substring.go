package longest_palindromic_substring

func longestPalindrome(s string) string {
	if len(s) == 1 {
		return s
	}
	lenOfLP := 0
	loOfLP, hiOfLP := 0, 0
	for i := 0; i < len(s)-1; i++ {
		if (len(s)-i)*2-1 < lenOfLP {
			break
		}
		lo, hi := getPalindrome(s, i, i+1)
		if hi-lo > lenOfLP {
			lenOfLP = hi - lo
			loOfLP, hiOfLP = lo, hi
		}
		if s[i] == s[i+1] {
			lo, hi := getPalindrome(s, i, i+2)
			if hi-lo > lenOfLP {
				lenOfLP = hi - lo
				loOfLP, hiOfLP = lo, hi
			}
		}
	}
	return s[loOfLP:hiOfLP]
}

func getPalindrome(s string, lo int, hi int) (int, int) {
	if s[lo] != s[hi-1] {
		return lo + 1, hi - 1
	}
	if lo == 0 || hi == len(s) {
		return lo, hi
	}
	return getPalindrome(s, lo-1, hi+1)
}
