all: dummy-01 3s-OMP

dummy-01:
	gcc -fopenmp -o dummy-01 dummy-01.c
3s-OMP:
	gcc -g -fopenmp -o 3s-OMP 3s-OMP.c
mxv:
	gcc -fopenmp -o mxvomp mxv.c
	gcc -o mxv mxv.c

clean:
	rm -f dummy-01 3s-OMP mxvopmp mxv
