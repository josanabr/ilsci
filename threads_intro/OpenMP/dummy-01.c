#include <stdio.h>
#include <omp.h>

main() {
	int n;
	#pragma omp parallel 
	{
		#pragma omp for 
		for (n = 0; n < 100; n++) {
			printf(" %d",n);
		}
	}
	printf(".\n");
}
