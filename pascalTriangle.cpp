#include <stdio.h>
#include <stdint.h>
#include <strings.h>

/* pascal's triangle */

uint64_t combination(int emptyBits, int bitsToFill)
{
    uint64_t oldResult[65];
    uint64_t newResult[65];
    bzero(oldResult, 64 * sizeof(uint64_t));
    bzero(newResult, 64 * sizeof(uint64_t));
    for (int row = 0; row <= emptyBits; row++) {
	memcpy(oldResult, newResult, 64 * sizeof(uint64_t));
	bzero(newResult, 64 * sizeof(uint64_t));
	for (int col = 0; col <= row; col++) {
	    if (col == 0 || col == emptyBits) {
		newResult[col] = 1;
	    } else {
		newResult[col] = oldResult[col - 1] + oldResult[col];
	    }
	    if (col == bitsToFill)
		break;
	}
    }
    return (newResult[bitsToFill]);
}


int main()
{
	printf("%llu\n", combination(3,2));
	printf("%llu\n", combination(60,12));
}
