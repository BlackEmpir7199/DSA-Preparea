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

        void print(){
            for(int i=0;i<size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};


int main(){
    MaxHeap h(6);
    h.insert(25);
    h.insert(30);
    h.insert(50);
    h.insert(23);
    h.insert(75);
    h.print();
    return 0;
}   