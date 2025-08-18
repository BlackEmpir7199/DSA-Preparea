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
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(n * 4);
        lazy.resize(n * 4, 0);
        build(arr, 0, 0, n - 1);
    }
};

int main()
{

    return 0;
}