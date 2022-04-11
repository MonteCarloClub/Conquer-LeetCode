package rotate_list

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k == 0 {
		return head
	}

	listNode := head
	length := 1
	for listNode.Next != nil {
		listNode = listNode.Next
		length++
	}
	listNode.Next = head

	result := head
	tail := listNode
	offset := k % length
	for i := 0; i < length-offset; i++ {
		result = result.Next
		tail = tail.Next
	}
	tail.Next = nil

	return result
}
