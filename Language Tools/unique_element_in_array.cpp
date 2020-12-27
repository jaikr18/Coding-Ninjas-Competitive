//In an array of size 2N+1, every element except one is repeated twice. find and print the unique element.

#include<iostream>
#include <algorithm>
using namespace std;

int findunique(int* arr, int size)
{
    int xOr = arr[0];
    for(int i=1;i<size;i++)
        xOr ^= arr[i];
    return xOr;
}

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

	cout<<findunique(input,size)<<endl;

	return 0;
}
