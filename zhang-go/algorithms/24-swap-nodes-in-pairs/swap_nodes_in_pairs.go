package swap_nodes_in_pairs

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	result := head.Next
	left := head
	for left != nil && left.Next != nil {
		right := left.Next
		nextLeft := right.Next
		right.Next = left
		if nextLeft == nil || nextLeft.Next == nil {
			left.Next = nextLeft
		} else {
			left.Next = nextLeft.Next
		}
		left = nextLeft
	}
	return result
}
