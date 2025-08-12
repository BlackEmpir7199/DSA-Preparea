#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> heap;
    bool isMinHeap;

    // Helper function to get parent index
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Compare function based on heap type
    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

    // Heapify down from index i
    void heapifyDown(int i) {
        int leftChild = left(i);
        int rightChild = right(i);
        int extremum = i;

        if (leftChild < heap.size() && compare(heap[leftChild], heap[extremum]))
            extremum = leftChild;
        if (rightChild < heap.size() && compare(heap[rightChild], heap[extremum]))
            extremum = rightChild;

        if (extremum != i) {
            swap(heap[i], heap[extremum]);
            heapifyDown(extremum);
        }
    }

    // Heapify up from index i
    void heapifyUp(int i) {
        while (i != 0 && compare(heap[i], heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Constructor: isMinHeap flag to determine heap type
    Heap(bool minHeap = true) {
        isMinHeap = minHeap;
    }

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    void pop() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
    }

    // Build heap from arbitrary array
    void buildHeap(const vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    int size() {
        return heap.size();
    }

    // Increase key for max heap (decrease for min heap)
    void increaseKey(int i, int newVal) {
        if (isMinHeap) {
            if (newVal > heap[i]) {
                heap[i] = newVal;
                heapifyDown(i);
            } else {
                // newVal is smaller or equal, so heapify up
                heap[i] = newVal;
                heapifyUp(i);
            }
        } else {
            if (newVal < heap[i]) {
                heap[i] = newVal;
                heapifyDown(i);
            } else {
                heap[i] = newVal;
                heapifyUp(i);
            }
        }
    }

    // Decrease key for max heap (increase for min heap)
    void decreaseKey(int i, int newVal) {
        increaseKey(i, newVal); // Handles both cases due to logic above
    }

    vector<int> getHeap() {
        return heap;
    }
};

// Heap Sort using max heap
void heapSort(vector<int>& arr) {
    Heap maxHeap(false); // max heap
    maxHeap.buildHeap(arr);
    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = maxHeap.top();
        maxHeap.pop();
    }
}

int main() {
    // Example usage:

    vector<int> data = {3, 1, 6, 5, 2, 4};
    Heap minHeap(true);
    minHeap.buildHeap(data);
    cout << "Min heap after build: ";
    for (int v : minHeap.getHeap()) cout << v << " ";
    cout << "\n";

    minHeap.push(0);
    cout << "Min heap after push(0): ";
    for (int v : minHeap.getHeap()) cout << v << " ";
    cout << "\n";

    minHeap.pop();
    cout << "Min heap after pop(): ";
    for (int v : minHeap.getHeap()) cout << v << " ";
    cout << "\n";

    cout << "Heap sort: ";
    heapSort(data);
    for (int v : data) cout << v << " ";
    cout << "\n";

    return 0;
}
