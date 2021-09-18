package decode_string

var (
	S    string
	FLAG int
)

func decodeString(s string) string {
	S = s
	FLAG = 0
	return getString()
}

func getString() string {
	if FLAG == len(S) || S[FLAG] == ']' {
		return ""
	}

	elem := S[FLAG]
	repeatedCount := 1
	leftString := ""
	if elem >= '0' && elem <= '9' {
		repeatedCount = getRepeatedCount()
		FLAG++ // Skip '['

		repeatedString := getString()
		FLAG++ // Skip ']'

		leftString = repeatString(repeatedString, repeatedCount)
	} else if elem >= 'a' && elem <= 'z' || elem >= 'A' && elem <= 'Z' {
		leftString = string(elem)
		FLAG++
	}
	return leftString + getString()
}

func getRepeatedCount() int {
	repeatedCount := 0
	for ; S[FLAG] >= '0' && S[FLAG] <= '9'; FLAG++ {
		repeatedCount = repeatedCount*10 + int(S[FLAG]-'0')
	}
	return repeatedCount
}

func repeatString(repeatedString string, repeatedCount int) string {
	result := ""
	for i := 0; i < repeatedCount; i++ {
		result += repeatedString
	}
	return result
}
