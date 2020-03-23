#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

main() {
	// declare the variables
	const int rolls = 19;
	int dice1, dice2, roll, suma = 0;
	int x = 0;
	// not sure whats wrong with srand, used as shown in the book p75, keeps giving me a warning
	srand(time(NULL));
	int ave[20];
	double sum[20];
	double stdv = 0.0;

	// roll a pair of dice 20 times
	while  (x <= rolls) {
		dice1 = (rand() % 6) + 1;
		dice2 = (rand() % 6) + 1;
		roll = dice1 + dice2;
		printf("\nRoll %d", x+1);
		printf(" is %d", roll);
		ave[x] = roll;
		suma += ave[x];
		x += 1;
	} // end while loop
	// calculate the summation for the standard deviation
	x = 0;
	while (x <= rolls) {
		sum[x] = (double)ave[x] - ((double)suma / (double)(rolls+1));
		stdv += sum[x] * sum[x];
		x += 1;
	} // end while loop
	// print the average and standard deviation of the dice rolls
	printf("\nThe average of the 20 rolls is %f", (float)suma / (float)(rolls+1));
	stdv = sqrt(stdv / (double)rolls);
	printf("\nThe standard deviation is %lf\n", stdv);
}