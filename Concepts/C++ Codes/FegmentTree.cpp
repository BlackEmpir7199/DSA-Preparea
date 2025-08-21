#include<bits/stdc++.h>

using namespace std;

class FenwickTree{
    private:
        vector<int> tree;
        int n;

        int query(int i){
            int ans=0;
            for(;i>0;i-=(i&-i))
                ans+=tree[i];
            return ans;
        }

        void pointUpdate(int i, int val){
            for(;i<=n;i+=(i&-i))
                tree[i]+=val;
        }

    public:
        FenwickTree(int n){
            // 1 based index - becoz 0 based indexing cant be used (i&-i) -> logic will break
            this->n = n;
            tree.assign(n+1,0);
        }

        void update(int i,int val){
            pointUpdate(i,val);
        }

        int rangeQuery(int l, int r){
            return query(r)-query(l-1);
        }

};


int main(){
    vector<int> arr={1, 2, 3, 4, 5};
    FenwickTree ft(5);
    for(int i=0;i<5;i++){
        ft.update(i+1,arr[i]);
    }
    cout << ft.rangeQuery(1,2);
    return 0;
}