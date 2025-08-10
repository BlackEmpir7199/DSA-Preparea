#include<bits/stdc++.h>

using namespace std;

class MaxHeap{
    public:
        int *arr;
        int size;
        int capacity;

        MaxHeap(int n){
            arr = new int[n];
            size = 0;
            capacity = n;
        }

        void insert(int data){
            if(size==capacity){
                cout << "Heap Overflow" << endl;
                return;
            }
            
            // insert data and inc size
            arr[size] = data;
            int idx = size;
            size++;
            
            // insertion logic to maintain max heap property
            int parentIdx = (idx-1)/2;
            while(idx>=0 && arr[parentIdx]<arr[idx]){
                swap(arr[parentIdx],arr[idx]);
                idx = parentIdx;
                parentIdx = (idx-1)/2;
            }

            // print to the user
            cout << arr[idx] << " Has been inserted." << endl;

        }

        void HeapifyDown(int idx){
            int largest = idx;
            int rightChild = 2*idx+1;
            int leftChild = 2*idx+2;


            // finds the largest element's idx to replace to the currrent temp root
            if(leftChild<size && arr[leftChild]>arr[largest]){
                largest = leftChild;
            }

            if(rightChild<size && arr[rightChild]>arr[largest]){
                largest = rightChild;
            }

            // when there is still a replacment available, repalce and recurse
            if(largest!=idx){
                swap(arr[largest],arr[idx]);
                HeapifyDown(largest);
            }

        }

        void remove(){
            if(size==0){
                cout<<"Heap Underflow"<< endl;
                return;
            }

            int removedRoot = arr[0];
            arr[0] = arr[size-1];
            size--;

            HeapifyDown(0);

            cout << removedRoot << " Has been removed" << endl;

        }

        void print(){
            for(int i=0;i<size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};


int main(){

    //Ex arr : [20, 15, 18, 10, 12, 16,5]

    // insertion
    MaxHeap h(7);
    h.insert(20);
    h.insert(15);
    h.insert(18);
    h.insert(10);
    h.insert(12);
    h.insert(16);
    h.insert(5);
    h.print();

    //after removal
    h.remove();
    h.print();
    
    return 0;
}   