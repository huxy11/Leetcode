#include "771.h"

#define M 128

int numJewelsInStones(char* J, char* S)
{
	uint32_t a[M];
	int32_t i =0;
	for (;i < M; i++)
		a[i] = 0;
	size_t len = strlen(J);
	for(;len > 0; len--)
		a[(int)J[len]]++;
	
	for (i = 0; i < M; i++)
		if (!a[i])
			printf("%d\n", i);


}
