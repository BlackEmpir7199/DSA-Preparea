#include<bits/stdc++.h>
using namespace std;

void leftRotateByK(vector<int> &arr, int k){
        
    int size = arr.size();
    vector<int> temp(k);

        for(int i=0;i<k;i++){
            temp[i] = arr[i];
        }

        for(int i=k;i<size;i++){
            arr[i-k] = arr[i];
        }

        for(int i=0;i<k;i++){
            arr[i+size-k] = temp[i];
        }

    }

void rightRotateByK(vector<int> &arr, int k){
        
    int size = arr.size();
    vector<int> temp(k);
        for(int i=size-k;i<size;i++){
            temp[i-(size-k)] = arr[i];
        }

        for(int i=1;i<=size-k;i++){
            arr[size-i] = arr[size-k-i];
        }

        for(int i=0;i<k;i++){
            arr[i] = temp[i];
        }

}


void universalRotateK(vector<int> &arr, int k){
    
}




int main(){
    
    vector<int> arr = {1,2,3,4,5,6,7};
    rightRotateByK(arr, 1);

    for(int i:arr) cout << i << " ";

    return 0;

}