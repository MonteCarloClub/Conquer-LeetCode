package lian_biao_zhong_dao_shu_di_kge_jie_dian

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func getKthFromEnd(head *ListNode, k int) *ListNode {
	lo, hi := head, head
	for i := 0; i < k; i++ {
		hi = hi.Next
	}
	for hi != nil {
		lo = lo.Next
		hi = hi.Next
	}
	return lo
}
