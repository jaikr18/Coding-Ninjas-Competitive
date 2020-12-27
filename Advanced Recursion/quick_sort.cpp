#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void partition(int* input, int left, int pivot, int right)
{
    int i = left, j = right;
    while(i < pivot && j > pivot)
    {
        if(input[i] >= input[pivot])
        {
            if(input[j] < input[pivot])
                swap(&input[i++],&input[j--]);
            else
                j--;
        }
        else if(input[j] < input[pivot])
            i++;
        else
        {
            i++; j--;
        }
    }
}

void quicksort(int* input, int left, int right)
{
    if(right > left)
    {
        int key = input[left];
        int small_count = 0;
        for(int i=left+1;i<=right;i++)
        {
            if(input[i] < key)
                small_count++;
        }
        input[left] = input[left + small_count];
        input[left + small_count] = key;

        partition(input,left,left+small_count,right);
        quicksort(input,left,left+small_count-1);
        quicksort(input,left+small_count+1,right);
    }
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quicksort(input,0,size-1);
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}
