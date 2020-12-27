/* custom input: 12
output: 4 */

#include <iostream>
using namespace std;

int returnFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n == 0)
        return 0;
    for(int i = 0;;i++)
    {
         if((n & (1<<i)) > 0)
             return 1<<i;
    }
}


int main() {
	int n;

	cin >> n;

	cout<< returnFirstSetBit(n) <<endl;

	return 0;
}
