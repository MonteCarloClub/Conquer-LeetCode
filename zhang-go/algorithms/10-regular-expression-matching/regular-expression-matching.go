package regular_expression_matching

func isMatch(s string, p string) bool {
	return isSubMatch(s, 0, len(s), p, 0, len(p))
}

func isMatchWithNil(p string, lop int, hip int) bool {
	if (hip-lop)%2 == 0 {
		r := lop + 1
		for r < hip {
			if p[r] != '*' {
				return false
			}
			r += 2
		}
		return true
	}
	return false
}

func isSubMatch(s string, los int, his int, p string, lop int, hip int) bool {
	// 递归基
	if los == his || lop == hip {
		if los == his && isMatchWithNil(p, lop, hip) {
			return true
		}
		return false
	}

	if s[his-1] == p[hip-1] || p[hip-1] == '.' {
		return isSubMatch(s, los, his-1, p, lop, hip-1)
	}

	if p[hip-1] == '*' /* assert hip-lop>=2 */ {
		r := his      /* s尾指针 */
		flag := false /* 匹配结果 */
		if p[hip-2] == '.' {
			for i := his; i >= los; i-- {
				flag = flag || isSubMatch(s, los, i, p, lop, hip-2)
				if flag {
					return true
				}
			}
			return false
		}
		lastElem := p[hip-2]
		for {
			flag = flag || isSubMatch(s, los, r, p, lop, hip-2)
			if flag {
				return true
			}
			if r == los || lastElem != s[r-1] {
				return false
			}
			r--
		}
	}
	return false
}
