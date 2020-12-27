/* custom input:
15 2
output: 3 */

#include <iostream>
using namespace std;

int clearAllBits(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return n & ((1<<i) - 1);
}

int main() {
	int n, i;

	cin >> n >> i;

	cout<< clearAllBits(n, i) <<endl;

	return 0;
}
