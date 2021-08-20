package lru_cache

type LRUCacheNode struct {
	key, value int
	pred, succ *LRUCacheNode
}

type LRUCache struct {
	size, capacity            int
	kv                        map[int]*LRUCacheNode
	dummyHeader, dummyTrailer *LRUCacheNode
}

func createLRUCacheNode(key, value int) *LRUCacheNode {
	return &LRUCacheNode{
		key:   key,
		value: value,
		pred:  nil,
		succ:  nil,
	}
}

func Constructor(capacity int) LRUCache {
	l := LRUCache{
		size:         0,
		capacity:     capacity,
		kv:           map[int]*LRUCacheNode{},
		dummyHeader:  createLRUCacheNode(0, 0),
		dummyTrailer: createLRUCacheNode(0, 0),
	}
	l.dummyHeader.succ = l.dummyTrailer
	l.dummyTrailer.pred = l.dummyHeader
	return l
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.kv[key]; !ok {
		return -1
	}
	node := this.kv[key]
	this.moveToHead(node)
	return node.value
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.kv[key]; !ok {
		node := createLRUCacheNode(key, value)
		this.kv[key] = node
		this.addToHead(node)
		if this.size < this.capacity {
			this.size++
		} else {
			removed := this.removeTail()
			delete(this.kv, removed.key)
		}
	} else {
		node := this.kv[key]
		node.value = value
		this.moveToHead(node)
	}
}

func (this *LRUCache) addToHead(node *LRUCacheNode) {
	node.pred = this.dummyHeader
	node.succ = this.dummyHeader.succ
	this.dummyHeader.succ.pred = node
	this.dummyHeader.succ = node
}

func (this *LRUCache) removeNode(node *LRUCacheNode) {
	node.pred.succ = node.succ
	node.succ.pred = node.pred
}

func (this *LRUCache) moveToHead(node *LRUCacheNode) {
	this.removeNode(node)
	this.addToHead(node)
}

func (this *LRUCache) removeTail() *LRUCacheNode {
	node := this.dummyTrailer.pred
	this.removeNode(node)
	return node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
