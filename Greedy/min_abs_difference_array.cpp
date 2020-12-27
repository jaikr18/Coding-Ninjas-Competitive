//Find the minimum absolute difference between any two elements in the array. 1 <=n <= 10^6

#include<bits/stdc++.h>
#include<climits>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	sort(arr,arr+n);
    int minimum = INT_MAX;
    for(int i=1;i<n;i++)
        if(arr[i] - arr[i-1] < minimum)
            minimum = arr[i] - arr[i-1];
    return minimum;
}

int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	cout<< minAbsoluteDiff(input,size) << endl;

	return 0;

}
