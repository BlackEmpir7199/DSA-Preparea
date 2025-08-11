#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MaxHeap(int cap)
    {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }

    void buildHeap(int inputArr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = inputArr[i];
        }
        size = n;
        capacity = n;
        build();
    }

    void insert(int data)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        // insert data and increment size
        arr[size] = data;
        int idx = size;
        size++;

        // insertion logic to maintain max heap property
        int parentIdx = (idx - 1) / 2;
        while (idx > 0 && arr[parentIdx] < arr[idx])
        {
            swap(arr[parentIdx], arr[idx]);
            idx = parentIdx;
            parentIdx = (idx - 1) / 2;
        }
        // print to the user
        cout << arr[idx] << " Has been inserted." << endl;
    }

    void HeapifyDown(int idx)
    {
        int largest = idx;
        int rightChild = 2 * idx + 2;
        int leftChild = 2 * idx + 1;

        // finds the largest element's index to replace the current temp root
        if (leftChild < size && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }
        if (rightChild < size && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
        // when there is still a replacement available, replace and recurse
        if (largest != idx)
        {
            swap(arr[largest], arr[idx]);
            HeapifyDown(largest);
        }
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }
        int removedRoot = arr[0];
        arr[0] = arr[size - 1];
        size--;
        HeapifyDown(0);
        cout << removedRoot << " Has been removed" << endl;
    }

    void build()
    {
        int parentIdx = (size / 2) - 1;
        for (int i = parentIdx; i >= 0; i--)
        {
            HeapifyDown(i);
        }
    }

    // Heap sort runs in O(n log n) - but not stable (duplicates order might not be the same as insertion order)
    void HeapSort()
    {
        int originalSize = size;
        for (int i = size - 1; i > 0; i--)
        {
            // this swap takes the largest element to the end each time this is done
            swap(arr[0], arr[i]);
            size--; // Decrease the size for heapify down
            // Heapify down takes i as the limiting size, this is for optimization since the last portion will be sorted
            HeapifyDown(0);
        }
        size = originalSize; // Restore the original size
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Example array: [20, 15, 18, 10, 12, 16, 5]
    // Insertion
    int arr[6] = {20, 15, 18, 2, 4, 1};
    MaxHeap h(6);
    h.buildHeap(arr, 6);
    h.print();
    // After sort
    h.HeapSort();
    h.print();

    return 0;
}
