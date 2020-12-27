/* You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence.
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12 */

#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

struct t
{
    int max1;
    int max2;
};

void buildtree(int* arr, t* tree, int start, int end, int treenode)
{
    if(start == end)
    {
        tree[treenode].max1 = arr[start];
        tree[treenode].max2 = INT_MIN;
        return;
    }

    int mid = (start + end)/2;

    buildtree(arr,tree,start,mid,2 * treenode);
    buildtree(arr,tree,mid+1,end,2 * treenode + 1);

    tree[treenode].max1 = max(tree[2*treenode].max1,tree[2*treenode+1].max1);
    tree[treenode].max2 = min(max(tree[2*treenode].max1,tree[2*treenode+1].max2),max(tree[2*treenode+1].max1,tree[2*treenode].max2));
}

void updatetree(int* arr, t* tree, int start, int end, int treenode, int index, int value)
{
    if(start == end)
    {
        tree[treenode].max1 = value;
        tree[treenode].max2 = INT_MIN;
        arr[index] = value;
        return;
    }

    int mid = (start + end)/2;
    if(mid < index)
        updatetree(arr,tree,mid+1,end,2*treenode+1,index,value);
    else
        updatetree(arr,tree,start,mid,2*treenode,index,value);

    tree[treenode].max1 = max(tree[2*treenode].max1,tree[2*treenode+1].max1);
    tree[treenode].max2 = min(max(tree[2*treenode].max1,tree[2*treenode+1].max2),max(tree[2*treenode+1].max1,tree[2*treenode].max2));
}

t querytree(t* tree, int start, int end, int treenode, int left, int right)
{
    //completely outside
    if(end < left || start > right)
    {
        t temp;
        temp.max1 = INT_MIN;
        temp.max2 = INT_MIN;
        return temp;
    }

    //completely inside
    if(start >= left && end <= right)
        return tree[treenode];

    else
    {
        int mid = (start + end)/2;
        t ans1 = querytree(tree,start,mid,2*treenode,left,right);
        t ans2 = querytree(tree,mid+1,end,2*treenode+1,left,right);

        int maximum = max(ans1.max1,ans2.max1);
        int s_maximum = min(max(ans1.max1,ans2.max2),max(ans1.max2,ans2.max1));

        t ans;
        ans.max1 = maximum;
        ans.max2 = s_maximum;
        return ans;
    }
}



int main() {

	int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    t* tree = new t[4 * n];

    buildtree(arr,tree,0,n-1,1);

    /*
    for(int i=1;i<2*n;i++)
        cout<<tree[i].max1<<" "<<tree[i].max2<<endl;
    */

    int q; cin>>q;
    while(q--)
    {
        char ch; int a,b;
        cin>>ch>>a>>b;
        if(ch == 'U')
            updatetree(arr,tree,0,n-1,1,a-1,b);
        else
        {
            t ans = querytree(tree,0,n-1,1,a-1,b-1);
            cout<<ans.max1 + ans.max2<<endl;
        }
    }

    return 0;
}
