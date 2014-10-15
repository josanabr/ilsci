#include <stdio.h>
#include <omp.h>

main() {
	#pragma omp parallel
	{
		printf("Hello\n");
	}
}
