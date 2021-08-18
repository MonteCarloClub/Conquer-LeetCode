package remove_duplicates_from_sorted_list_ii

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	result := &ListNode{-1, nil}
	flag := result
	predVal := head.Val
	countOfVal := 1
	head = head.Next
	for head != nil {
		if head.Val == predVal {
			countOfVal++
		} else {
			if countOfVal == 1 {
				flag.Next = &ListNode{predVal, nil}
				flag = flag.Next
			}
			predVal = head.Val
			countOfVal = 1
		}
		head = head.Next
	}
	if countOfVal == 1 {
		flag.Next = &ListNode{predVal, nil}
	}
	return result.Next
}
