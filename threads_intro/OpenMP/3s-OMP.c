#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define MAX_THREADS 4
#define VECTOR_SIZE 1000000000

pthread_t tid[MAX_THREADS];

int *array;
int count = 0;
int double_count = 0;

void initialize_vector() {
	int i = 0;
	int dummy_count = 0;
	array = (int*) malloc(sizeof(int) * VECTOR_SIZE);
	if (array == NULL) {
		printf("Allocation memory failed!\n");
		exit(-1);
	}
	#pragma omp parallel default(none) shared(array,double_count) private(dummy_count)
	{
		dummy_count = 0;
		printf("Initializing vector [%d]\n",omp_get_thread_num());
		#pragma omp for schedule(dynamic) private(i)
		for (i = 0; i < VECTOR_SIZE; i++) {
			array[i] = rand() % 20;
			if (array[i] == 3)
				dummy_count++;
		}
		printf("Exiting [%d]\n",omp_get_thread_num());
		#pragma omp critical 
		{
			double_count += dummy_count;
		}
	} 
}

void count_3s() {
	int i = 0;
	for (; i < VECTOR_SIZE; i++) {
		if (array[i] == 3) count++;
	}
}

int main(void) {
	int i = 0;
	int err;
	// random seed
	// http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	srand(time(NULL));
	printf("Initializing vector... ");
	fflush(stdout);
	initialize_vector();
	printf("Vector initialized!\n");
	fflush(stdout);
	count_3s();
	printf("Count by threads %d\n", count);
	printf("Double check %d\n", double_count);
	return 0;
}

