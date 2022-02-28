package top_k_frequent_elements

func topKFrequent(nums []int, k int) []int {
	freqMap := make(map[int]int)
	for _, elem := range nums {
		if _, ok := freqMap[elem]; ok {
			freqMap[elem]++
		} else {
			freqMap[elem] = 1
		}
	}

	minHeap := make([]int, 0)
	for elem, freq := range freqMap {
		if len(minHeap) == k {
			for i := k / 2; i >= 0; i-- {
				minHeapify(minHeap, freqMap, i, k)
			}
		}

		if len(minHeap) < k {
			minHeap = append(minHeap, elem)
		} else {
			if freqMap[minHeap[0]] > freq {
				continue
			}
			minHeap[0] = elem
			minHeapify(minHeap, freqMap, 0, k)
		}
	}
	return minHeap
}

func minHeapify(minHeap []int, freqMap map[int]int, i int, k int) {
	leftChild, rightChild, min := i*2+1, i*2+2, i
	if leftChild < k && freqMap[minHeap[leftChild]] < freqMap[minHeap[min]] {
		min = leftChild
	}
	if rightChild < k && freqMap[minHeap[rightChild]] < freqMap[minHeap[min]] {
		min = rightChild
	}
	if min != i {
		minHeap[min], minHeap[i] = minHeap[i], minHeap[min]
		minHeapify(minHeap, freqMap, min, k)
	}
}
