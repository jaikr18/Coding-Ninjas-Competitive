/* custom input: 12
output: 8 */

#include <iostream>
using namespace std;

int turnOffFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n == 0)
        return n;
    for(int i = 0;;i++)
    {
        if((n & (1<<i)) > 0)
            return n & ~(1<<i);
    }
}

int main() {
	int n;

	cin >> n;

	cout<< turnOffFirstSetBit(n) <<endl;

	return 0;
}
