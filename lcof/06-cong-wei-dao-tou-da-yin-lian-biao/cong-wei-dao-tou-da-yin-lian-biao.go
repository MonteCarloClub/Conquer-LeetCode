package cong_wei_dao_tou_da_yin_lian_biao

// ListNode Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	const (
		maxLen = 10000
	)
	sol := make([]int, maxLen)
	flag := head
	i := maxLen
	for i >= 0 && flag != nil {
		i--
		sol[i] = flag.Val
		flag = flag.Next
	}
	return sol[i:maxLen]
}
