/* custom input:
4 4
output:
20 */

#include <iostream>
using namespace std;

int turnOnIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return (n|(1<<i));
}

int main() {
	int n, i;

	cin >> n >> i;

	cout<< turnOnIthBit(n, i) <<endl;

	return 0;
}
