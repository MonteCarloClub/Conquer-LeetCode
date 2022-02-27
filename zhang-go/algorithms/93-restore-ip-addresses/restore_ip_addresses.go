package restore_ip_addresses

import (
	"strconv"
)

var (
	result []string
)

func restoreIpAddresses(s string) []string {
	result = make([]string, 0)
	record := make([]string, 4)
	dfs(s, 0, 0, record)
	return result
}

func dfs(s string, r int, segId int, record []string) {
	// 构造完成4段
	if segId == 4 {
		// 当且仅当恰好遍历完 s，构造 IP
		if r == len(s) {
			ip := ""
			for i, seg := range record {
				ip += seg
				if i <= 2 {
					ip += "."
				}
			}
			result = append(result, ip)
		}
		return
	}

	// 提前结束
	if r == len(s) {
		return
	}

	if s[r] == '0' {
		record[segId] = s[r : r+1]
		dfs(s, r+1, segId+1, record)
	} else {
		for i := r + 1; i <= len(s); i++ {
			num, _ := strconv.Atoi(s[r:i])
			if num >= 0 && num <= 255 {
				record[segId] = s[r:i]
				dfs(s, i, segId+1, record)
			} else {
				break
			}
		}
	}
}
