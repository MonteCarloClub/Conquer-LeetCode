package merge_k_sorted_lists

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	return mergeLists(lists, 0, len(lists))
}

func mergeTwoLists(x *ListNode, y *ListNode) *ListNode {
	dummyHeader := &ListNode{
		Next: nil,
	}
	xFlag, yFlag, flag := x, y, dummyHeader
	for x != nil || y != nil {
		if xFlag == nil {
			flag.Next = yFlag
			break
		}
		if yFlag == nil {
			flag.Next = xFlag
			break
		}
		if xFlag.Val < yFlag.Val {
			flag.Next = xFlag
			xFlag = xFlag.Next
		} else {
			flag.Next = yFlag
			yFlag = yFlag.Next
		}
		flag = flag.Next
	}
	return dummyHeader.Next
}

func mergeLists(lists []*ListNode, lo int, hi int) *ListNode {
	if hi-lo == 0 {
		return nil
	}
	if hi-lo == 1 {
		return lists[lo]
	}
	if hi-lo == 2 {
		return mergeTwoLists(lists[lo], lists[lo+1])
	}
	mi := (lo + hi) / 2
	return mergeTwoLists(mergeLists(lists, lo, mi), mergeLists(lists, mi, hi))
}
