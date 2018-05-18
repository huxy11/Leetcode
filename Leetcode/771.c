#include "771.h"

#define M 128

int numJewelsInStones(char* J, char* S)
{
    uint32_t lo = 'A';
    uint32_t hi = 'z';
	uint32_t a[M];
    uint32_t sum = 0;
	int32_t i =0;
	for (;i < M; i++)
		a[i] = 0;
	size_t len = strlen(J);
    for(i = 0; i < len; i++) {
        if (J[i] <= hi && J[i] >= lo)
            a[J[i]] = 1;
    }
    len = strlen(S);
    for(i = 0; i < len; i++) {
        sum += a[S[i]];
    }
    return sum;
}
