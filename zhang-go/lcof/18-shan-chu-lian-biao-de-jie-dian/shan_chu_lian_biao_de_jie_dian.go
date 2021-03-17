package shan_chu_lian_biao_de_jie_dian

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(head *ListNode, val int) *ListNode {
	if head.Val == val {
		return head.Next
	}
	flag, predOfflag := head, head
	for predOfflag.Next != nil {
		if flag.Val == val {
			predOfflag.Next = flag.Next
			break
		}
		predOfflag = flag
		flag = flag.Next
	}
	return head
}
