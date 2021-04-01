class Solution {
public:
    void maxHeapify(vector<int>& heap, int root, int heapSize) {
        int left = root * 2 + 1, right = root * 2 + 2, largest = root;
        if (left < heapSize && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heapSize && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != root) {
            swap(heap[root], heap[largest]);
            maxHeapify(heap, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& heap, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(heap, i, heapSize);
        }
    }

    int popMax(vector<int>& heap, int heapSize) {
        swap(heap[0], heap[heapSize-1]);
        maxHeapify(heap, 0, heapSize-1);
        return heap[heapSize-1];
    }

    int findKthLargest(vector<int>& nums, int k) {
        int result, heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = 0; i < k; ++i) {
            result = popMax(nums,heapSize);
            --heapSize;
        }       
        return result;
    }
};
