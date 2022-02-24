package reverse_linked_list_ii

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	dummyHead := &ListNode{
		Next: head,
	}
	pred := dummyHead
	for i := 0; i < left-1; i++ {
		pred = pred.Next
	}

	current := pred.Next
	for i := 0; i < right-left; i++ {
		next := current.Next
		current.Next = next.Next
		next.Next = pred.Next
		pred.Next = next
	}

	return dummyHead.Next
}
