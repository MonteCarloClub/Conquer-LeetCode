package add_two_numbers

// ListNode Singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	header := &ListNode{} /* 首节点，从它的后继开始存储答案 */
	flag := header
	carry := 0 /* 进位 */
	// 跳出循环条件：2个列表遍历结束且无进位
	for l1 != nil || l2 != nil || carry == 1 {
		sum := carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		if sum > 9 {
			carry = 1
			sum -= 10
		} else {
			carry = 0
		}
		flag.Next = &ListNode{Val: sum}
		flag = flag.Next
	}
	return header.Next
}
