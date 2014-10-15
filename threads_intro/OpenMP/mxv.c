#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void mxv(int m, int n, 
         double *a, 
         double *b, 
         double *c);

void mxvomp(int m, int n, 
         double *a, 
         double *b, 
         double *c);

int main(int argc, char *argv[]) {
	clock_t t1, t2;
	double *a, *b, *c;
	int i, j, m, n;

	if (argc == 3) {
		printf("m = %d\n",m = atoi(argv[1]));
		printf("n = %d\n",n = atoi(argv[2]));
	} else {
		printf("Please give m and n: ");
		scanf("%d %d", &m, &n);
	}

	if ( (a = (double*)malloc(m*sizeof(double))) == NULL) {
		perror("memory allocation for a");
		exit(-1);
	}
	if ( (b = (double*)malloc(m*n*sizeof(double))) == NULL) {
		perror("memory allocation for b");
		exit(-1);
	}
	if ( (c = (double*)malloc(n*sizeof(double))) == NULL) {
		perror("memory allocation for a");
		exit(-1);
	}

	printf("Initializing matrix B and vector c\n");
	for (j = 0; j < n; j++)
		c[j] = 2.0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			b[i*n+j] = i;

	printf("Executing mxv function for m = %d n = %d\n", m, n);
	t1 = clock();
	(void) mxvomp(m, n, a, b, c);
	t2 = clock();
	printf("Elapsed time %f\n", (((float)t2 - (float)t1) / 1000000.0F ) * 1000);

	free(a); free(b); free(c);

	return 0;
}

void mxv(int m, int n, 
         double *a, 
         double *b, 
         double *c){
	int i,j;
	for (i = 0; i < m; i++) {
		a[i] = 0.0;
		for (j = 0; j < n; j++)
			a[i] += b[i*n+j]*c[j];
	}
}

void mxvomp(int m, int n, 
         double *a, 
         double *b, 
         double *c){
	int i,j;
#if defined(_OPENMP)
	printf("Using OpenMP\n");
#endif
	#pragma omp parallel for default(none) shared(m,n,a,b,c) private(i,j)
	for (i = 0; i < m; i++) {
		a[i] = 0.0;
		for (j = 0; j < n; j++) 
			a[i] += b[i*n+j]*c[j];
	}
}
