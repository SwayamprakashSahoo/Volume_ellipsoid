#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

double volume(int N);
double plot(int N);


void main()
{
	FILE* fptr;
	fptr = fopen("C:/Users/sahoo/Desktop/Ellipsoid/volume.txt", "w");

	double a, b, c, err;
	a = 1.0;
	b = 1.5;
	c = 2.0;
	double v = (4 * 22 * a * b * c) / (3 * 7);

	int N = 500;
	while (N <= 50000)
	{
		double V = volume(N);
		err = (v - V) / v;
		fprintf(fptr, "%d\t%lf\t%lf\n", N, V, err);
		N += 100;
	}
	plot(20000);
	printf("\nEvaluation of volume of Ellipsoid using Monte-Carlo method completed.\nResults stored in location 'C:/Users/sahoo/Desktop/Ellipsoid/volume.txt'");

}


double volume(int N)
{
	double a, b, c;
	a = 1.0;
	b = 1.5;
	c = 2.0;
	int hits = 0;
	double x, y, z;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		//generating coordinates
		x = 2 * a * (rand() / (double)RAND_MAX) - a;
		y = 2 * b * (rand() / (double)RAND_MAX) - b;
		z = 2 * c * (rand() / (double)RAND_MAX) - c;
		
		double num = ((x * x) /( a * a)) + ((y * y) / (b * b)) + ((z * z) / (c * c));
		if (num <= 1)
			hits++;
	}

	double V = 8 * a * b * c * ((double)hits /(double) N); //Volume
		//returning calculated volume
	return V;
}

double plot(int N)
{
	FILE* fptr1;
	fptr1 = fopen("C:/Users/sahoo/Desktop/Ellipsoid/coordinates.txt", "w");    //plot data file

	double a, b, c;
	a = 1;
	b = 1.5;
	c = 2;

	double x, y, z;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		x = (rand() / (double)RAND_MAX) * 2 * a - a;
		y = (rand() / (double)RAND_MAX) * 2 * b - b;
		z = (rand() / (double)RAND_MAX) * 2 * c - c;

		double num = ((x * x) / (a * a)) + ((y * y) / (b * b)) + ((z * z) / (c * c));
		if (num <= 1)
			fprintf(fptr1, "%lf\t%lf\t%lf\n", x, y, z);		//coordinates to be plotted
	}
	fclose(fptr1);
}

