package yong_liang_ge_zhan_shi_xian_dui_lie

type IntegerStack struct {
	arr  []int
	rank int
}

func NewIntegerStack() *IntegerStack {
	return &IntegerStack{
		arr:  make([]int, 10000),
		rank: 0,
	}
}

func (is *IntegerStack) AppendElem(value int) {
	is.arr[is.rank] = value
	is.rank++
}

func (is *IntegerStack) DeleteElem() int {
	if is.rank > 0 {
		is.rank--
		return is.arr[is.rank]
	}
	return -1
}

func (is *IntegerStack) GetRank() int {
	return is.rank
}

type CQueue struct {
	stackIn  *IntegerStack
	stackOut *IntegerStack
}

func Constructor() CQueue {
	return CQueue{
		stackIn:  NewIntegerStack(),
		stackOut: NewIntegerStack(),
	}
}

func (this *CQueue) AppendTail(value int) {
	this.stackIn.AppendElem(value)
}

func (this *CQueue) DeleteHead() int {
	if this.stackOut.GetRank() > 0 {
		return this.stackOut.DeleteElem()
	}
	len := this.stackIn.GetRank()
	for i := 0; i < len; i++ {
		this.stackOut.AppendElem(this.stackIn.DeleteElem())
	}
	return this.stackOut.DeleteElem()
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
