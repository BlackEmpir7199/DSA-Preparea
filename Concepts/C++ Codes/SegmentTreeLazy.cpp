#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{

private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(arr, node * 2 + 1, start, mid);
        build(arr, node * 2 + 2, mid + 1, end);

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    void propagate(int node, int start, int end)
    {
        /*
        In propagate we, find any lazy node should be updated , and if yes, then we update it, and propagte the changes to the child and then remove the current lazy node, set it to zero
        */
       if(lazy[node]!=0){
            tree[node]+=lazy[node]*(end-start+1);

            // mark their children for updates
            if(end!=start){
                lazy[node*2+1] += lazy[node];
                lazy[node*2+2] += lazy[node];
            }

            lazy[node]=0;
       }
    }

    // to perform range updates
    void update(int node, int start, int end, int l, int r, int val){
        propagate(node,start,end);

        // no overlap
        if(end<l || start>r) return;

        // complete overlap
        if(l<=start && r>=end){
            tree[node]+=val*(end-start+1);

            if(start!=end){
                lazy[node*2+1]+=val;
                lazy[node*2+2]+=val;
            }
            return;
        }

        // partial overlap
        int mid = (start+end)/2;
        update(node*2+1,start,mid,l,r,val);
        update(node*2+2,mid+1,end,l,r,val);
        tree[node]=tree[node*2+1]+tree[node*2+2];

    }

    int query(int node, int start, int end, int l, int r){
        propagate(node,start,end);
        // no overlap
        if(end<l || start>r) return 0;

        // complete overlap
        if(l<=start && r>=end){
            return tree[node];
        }

        int mid = (start+end)/2;
        int lSum = query(node*2+1,start,mid,l,r);
        int rSum = query(node*2+2,mid+1,end,l,r);
        return lSum+rSum;
        
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(n * 4);
        lazy.resize(n * 4, 0);
        build(arr, 0, 0, n - 1);
    }

    int rangeQuery(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void update(int l, int r, int val)
    {
        update(0, 0, n - 1, l, r, val);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree sgt(arr);

    cout << sgt.rangeQuery(0, 1);
    return 0;
}