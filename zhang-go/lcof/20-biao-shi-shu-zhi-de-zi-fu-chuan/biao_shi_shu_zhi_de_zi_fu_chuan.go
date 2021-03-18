package biao_shi_shu_zhi_de_zi_fu_chuan

func isNumber(s string) bool {
	lo, hi := 0, len(s)
	// 忽略前缀和后缀空格，其他位置的空格不被允许
	for ; lo < hi; lo++ {
		if s[lo] != ' ' {
			break
		}
	}
	for ; lo < hi; hi-- {
		if s[hi-1] != ' ' {
			break
		}
	}
	if lo == hi {
		return false
	}
	s = s[lo:hi]
	// 针对小数和科学记数法讨论和判断
	rankOfDecimalPoint, rankOfEe := isDecimalAndSciNotation(s)
	if rankOfDecimalPoint == -1 && rankOfEe == -1 /* 仅允许整数 */ {
		return isInteger(s)
	} else if rankOfDecimalPoint == -1 /* 不包含小数点的科学记数法 */ {
		if len(s[:rankOfEe]) == 0 && len(s[rankOfEe:]) == 1 {
			return false
		}
		return isInteger(s[:rankOfEe]) && isInteger(s[rankOfEe+1:])
	} else if rankOfEe == -1 /* 纯小数 */ {
		return isDecimal(s, rankOfDecimalPoint)
	}
	// 同时是小数和科学记数法，小数部分必然是指数
	if len(s[rankOfEe:]) == 1 || rankOfDecimalPoint > rankOfEe {
		return false
	}
	return isDecimal(s[:rankOfEe], rankOfDecimalPoint) && isInteger(s[rankOfEe+1:])
}

// isDecimalOrSciNotation返回字符串是否表示小数和科学记数法
// 是返回对应符号（“.”、“E”、“e”）的秩；否（包含超过1个对应符号的情况）返回-1
func isDecimalAndSciNotation(s string) (int, int) {
	var rankOfDecimalPoint, rankOfEe int
	countOfDecimalPoint := 0
	countOfEe := 0
	for i, elem := range s {
		if elem == '.' {
			rankOfDecimalPoint = i
			countOfDecimalPoint++
		} else if elem == 'E' || elem == 'e' {
			rankOfEe = i
			countOfEe++
		}
	}
	if countOfDecimalPoint != 1 {
		rankOfDecimalPoint = -1
	}
	if countOfEe != 1 {
		rankOfEe = -1
	}
	return rankOfDecimalPoint, rankOfEe
}

func isNaturalNumber(s string) bool {
	if len(s) == 0 {
		return false
	}
	for _, elem := range s {
		switch elem {
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			break
		default:
			return false
		}
	}
	return true
}

func isInteger(s string) bool {
	if len(s) == 0 {
		return false
	}
	for i, elem := range s {
		if elem != '+' && elem != '-' {
			return isNaturalNumber(s[i:])
		}
	}
	return false /* 全是“+”和“-” */
}

func isDecimal(s string, r int) bool {
	lo := -1
	for i, elem := range s {
		if elem != '+' && elem != '-' {
			lo = i
			break
		}
	}
	if lo == -1 {
		return false
	}
	if len(s[lo:r]) == 0 && len(s[r:]) == 1 {
		return false
	}
	return (len(s[lo:r]) == 0 || isNaturalNumber(s[lo:r])) && (len(s[r:]) == 1 || isNaturalNumber(s[r+1:]))
}
