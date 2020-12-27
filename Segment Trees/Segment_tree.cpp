#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void buildtree(int* arr, int* tree, int start, int end, int index)
{
    if(start == end)
    {
        tree[index] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildtree(arr,tree,start,mid,2*index);
    buildtree(arr,tree,mid+1,end,2 * index + 1);

    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

void updatetree(int* arr, int* tree, int start, int end, int treenode, int index, int value)
{
    if(start == end)
    {
        arr[index] = value;
        tree[treenode] = value;
        return;
    }

    int mid = (start + end)/2;
    if(index > mid)
        updatetree(arr,tree,mid+1,end,2*treenode+1,index,value);
    else
        updatetree(arr,tree,start,mid,2*treenode,index,value);

    tree[treenode] = tree[2 * treenode] + tree[2 * treenode + 1];
}

int querytree(int* tree, int start, int end, int treenode, int left, int right)
{
    //completely outside
    if(end < left || start > right)
        return 0;

    //completely inside
    else if(start >= left && end <= right)
        return tree[treenode];

    //partially inside and outside
    else
    {
        int mid = (start + end)/2;
        int ans1 =  querytree(tree,start,mid,2*treenode,left,right);
        int ans2 = querytree(tree,mid+1,end,2*treenode+1,left,right);

        return ans1 + ans2;
    }
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    int* tree = new int[2 * n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    buildtree(arr,tree,0,n-1,1);

    updatetree(arr,tree,0,n-1,1,2,10);

    for(int i =1;i<2* n;i++)
        cout<<tree[i]<<" ";

    cout<<endl<<querytree(tree,0,n-1,1,2,4);

}
