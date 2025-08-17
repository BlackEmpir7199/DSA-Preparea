#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int n;

    // building the segment tree
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

        // sum the left child and right child and put it to the current node
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    // querying the segment tree
    int query(int node, int start, int end, int l, int r)
    {

        // case 1: No overlap
        if (r < start || l > end)
            return 0;

        // case 2: Complete overlap
        if (l <= start && r >= end)
            return tree[node];

        // case 3: Partial Overlap
        int mid = (start + end) / 2;
        int lSum = query(node * 2 + 1, start, mid, l, r);
        int rSum = query(node * 2 + 2, mid + 1, end, l, r);
        return lSum + rSum;
    }

    // point updating the segment tree
    void update(int node, int start, int end, int idx, int val)
    {
        // we will find the needed idx and change the val there
        if (start == end)
        {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        // calling the recursion using our idx
        if (idx <= mid)
            update(node * 2 + 1, start, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, end, idx, val);

        // assume the upper part of the code works fine ; then we should once again reupdate the value of the currrent node acc to the parent
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(n * 4);
        build(arr, 0, 0, n - 1);
    }

    int rangeSum(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int val)
    {
        update(0, 0, n - 1, idx, val);
    }
};

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50, 60};

    SegmentTree tree(arr);

    cout << tree.rangeSum(0, 5);

    return 0;
}