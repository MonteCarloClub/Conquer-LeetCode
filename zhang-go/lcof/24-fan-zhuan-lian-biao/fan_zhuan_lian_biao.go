package fan_zhuan_lian_biao

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	left, right := head, head.Next
	head.Next = nil
	for right != nil {
		nextRight := right.Next
		right.Next = left
		left = right
		right = nextRight
	}
	return left
}
