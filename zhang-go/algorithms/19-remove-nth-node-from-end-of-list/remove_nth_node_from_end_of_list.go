package remove_nth_node_from_end_of_list

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	mapOfListNodes := map[int]*ListNode{}
	length := 0
	flag := head
	for flag != nil {
		mapOfListNodes[length] = flag
		length++
		flag = flag.Next
	}
	if n == length {
		return head.Next
	}
	mapOfListNodes[length-n-1].Next = mapOfListNodes[length-n].Next
	return head
}
