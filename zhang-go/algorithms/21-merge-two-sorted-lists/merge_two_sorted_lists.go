package merge_two_sorted_lists

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var header *ListNode
	if min(l1, l2) == 0 {
		header = l1
		header.Next = mergeTwoLists(l1.Next, l2)
	} else {
		header = l2
		header.Next = mergeTwoLists(l1, l2.Next)
	}
	return header
}

func min(x *ListNode, y *ListNode) int {
	if x.Val < y.Val {
		return 0
	}
	return 1
}
