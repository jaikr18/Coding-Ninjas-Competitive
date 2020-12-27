/* You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible. */

#include<iostream>
using namespace std;


int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int** change = new int*[value+1];
    for(int i=0;i<=value;i++)
    {
        change[i] = new int[numDenominations];
        for(int j=0;j<numDenominations;j++)
            change[i][j] = 1;
    }
    for(int i=1;i<=value;i++)
    {
        for(int j=0;j<numDenominations;j++)
        {
            int including = (i - denominations[j] >= 0)? change[i-denominations[j]][j] : 0;
            int excluding = (j > 0)? change[i][j-1] : 0;

            change[i][j] = including + excluding;
        }
    }

    return change[value][numDenominations-1];


}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}
