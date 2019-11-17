/*  RAHMANI TAHA ABDELAZIZ */


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#define NSTEPS 100000000000000
#define NTHREADS 4
int main(){
float pi = 0;
float pi_prime = 0;

	printf(" ------------ Le calcul de pi en sequentiel ---------------\n");
	double start = omp_get_wtime();
	
	for (long i = 0; i <= NSTEPS; i++){

		pi += pow(-1,i)/(2*i+1)* 4; 


	}

	double fin = omp_get_wtime() - start;

	printf(" la valeur de pi  = %f \n", pi);
	printf(" le temps sequentiel  = %f \n", fin);


	pi = 0;
	fin = start = 0;
	


	printf("------------ Le calcul de pi en parrallel -------------\n");


	start = omp_get_wtime();
	#pragma omp parallel private(pi_prime)  reduction(+: pi) num_threads(NTHREADS) 
	{

		#pragma omp for  
		for (long i = 0; i <= NSTEPS; i++)

			pi_prime += pow(-1,i)/(2*i+1)* 4; 


	
	
		pi += pi_prime;
	
	
	}
	
	fin = omp_get_wtime() - start;
	printf(" La valeur de pi = %f \n", fin);
	printf(" le temps parallel  = %f \n", pi);








	return 0;
}
