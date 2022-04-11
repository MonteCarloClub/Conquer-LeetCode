package implement_trie_prefix_tree

type Trie struct {
	isLeaf   bool
	children [26]*Trie
}

func Constructor() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	node := this
	for _, elem := range word {
		r := elem - 'a'
		if node.children[r] == nil {
			node.children[r] = &Trie{}
		}
		node = node.children[r]
	}
	node.isLeaf = true
}

func (this *Trie) Search(word string) bool {
	node := this
	for _, elem := range word {
		r := elem - 'a'
		if node.children[r] == nil {
			return false
		}
		node = node.children[r]
	}
	return node.isLeaf
}

func (this *Trie) StartsWith(prefix string) bool {
	node := this
	for _, elem := range prefix {
		r := elem - 'a'
		if node.children[r] == nil {
			return false
		}
		node = node.children[r]
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
