package reverse_nodes_in_k_group

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	dummyHead := &ListNode{
		Next: head,
	}

	pred := dummyHead
	for head != nil {
		tail := pred

		for i := 0; i < k; i++ {
			tail = tail.Next
			if tail == nil {
				return dummyHead.Next
			}
		}

		nextHead := tail.Next
		head, tail = reverse(head, tail)

		pred.Next = head
		tail.Next = nextHead

		pred = tail
		head = tail.Next
	}
	return dummyHead.Next
}

func reverse(head, tail *ListNode) (*ListNode, *ListNode) {
	pred := tail.Next
	p := head
	// pred, p, nextP
	for pred != tail {
		nextP := p.Next
		p.Next = pred
		pred = p
		p = nextP
	}
	return tail, head
}
