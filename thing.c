#include <stdio.h>
#include <math.h>

int main() {
	// Check if we're calculating one or two proportions.
	int isDiff;
	printf("0: one proportion\n1: difference in proportions\n");
	printf("Enter choice here: ");
	scanf("%d", &isDiff);

	// Enforce input.
	while ((isDiff != 0) && (isDiff != 1)) {
		printf("Invalid input. Try again: ");
		scanf("%d", &isDiff);
	}

	// Get proportion and sample size from user.
	float prop;
	printf("Enter the proportion you want to calculate (e.g. '0.06'): ");
	scanf("%f", &prop);
	int n;
	printf("Enter the sample size, n: ");
	scanf("%d", &n);

	// If isDiff is 1, get second proportion and sample size.
	float prop2 = 1;
	int n2;
	if (isDiff == 1) {
		printf("Enter the second proportion: ");
		scanf("%f", &prop2);
		printf("Enter the second sample size: ");
		scanf("%d", &n2);
	}

	// Get the confidence level.
	int conf_level;
	printf("Enter the confidence level (90, 95, 99): ");
	scanf("%d", &conf_level);

	// This program only concerns 90, 95, and 99% Z-intervals.
	// Checking for those.
	while ((conf_level != 90) && (conf_level != 95) && (conf_level != 99)) {
		printf("Invalid. Enter 90, 95, or 99: ");
		scanf("%d", &conf_level);
	}

	// Set the z-score based on those values.
	float zScore;
	if (conf_level == 95) {
		zScore = 1.9599639;
	} else if (conf_level == 99) {
		zScore = 2.5758293;
	} else {
		zScore = 1.6448536;
	}

	// Calculate confidence interval.
	float upper, lower, MoE, tempVar;
	if (isDiff == 0) {
		tempVar = (prop*(1-prop)) / n;
		MoE = zScore * sqrt(tempVar);
		lower = prop - MoE;
		upper = prop + MoE;
	} else {
		tempVar = ((prop*(1-prop)) / n) + ((prop2*(1-prop2)) / n2);
		MoE = zScore * sqrt(tempVar);
		lower = (prop - prop2) - MoE;
		upper = (prop - prop2) + MoE;
	}

	// Display confidence interval and margin of error.
	printf("The condfidence interval is (%f, %f).\n", lower, upper);
	printf("The margin of error is %f\n", MoE);

	// Repeat for my purposes.
	int cont;
	if (isDiff == 0) {
		cont;
		printf("Do you want to repeat? ");
		scanf("%d", &cont);
	}

	// Enforce input.
	if ((cont != 1) && (cont != 0)) {
		printf("Invalid ");
		scanf("%d", &cont);
	}

	while (cont == 1) {
		printf("\nEnter another proportion. ");
		scanf("%f", &prop);
		tempVar = (prop*(1-prop)) / n;
		MoE = zScore * sqrt(tempVar);
		lower = prop - MoE;
		upper = prop + MoE;
		printf("The condfidence interval is (%f, %f).\n", lower, upper);
        	printf("The margin of error is %f\n", MoE);

		printf("Do you want to repeat? ");
		scanf("%d", &cont);
		
		if ((cont != 1) && (cont != 0)) {
			printf("Invalid ");
			scanf("%d", &cont);
		}
	}

	return 0;

}
