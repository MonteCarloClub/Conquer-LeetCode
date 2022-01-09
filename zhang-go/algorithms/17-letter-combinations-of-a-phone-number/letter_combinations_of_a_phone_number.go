package letter_combinations_of_a_phone_number

var dialMap map[string]string = map[string]string{
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz",
}

var combinations []string

func letterCombinations(digits string) []string {
	combinations = []string{}
	if len(digits) == 0 {
		return nil
	}
	backtrack(digits, 0, "")
	return combinations
}

func backtrack(digits string, rank int, combination string) {
	if rank == len(digits) {
		combinations = append(combinations, combination)
	} else {
		letters := dialMap[string(digits[rank])]
		for i := 0; i < len(letters); i++ {
			backtrack(digits, rank+1, combination+string(letters[i]))
		}
	}
}
