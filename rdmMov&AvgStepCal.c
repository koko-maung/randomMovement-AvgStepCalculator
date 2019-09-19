/*Instructor-Professor Geiger
Ko Ko Maung
2/3/2018
This program request user to enter seed, size of the city, starting position
and the number of trial and then it produce random movement and calculate avg steps.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, const char* argv[])
{
	int s, n;								                           //s=seed
	char j;									                           //j=junk
	int X, Y, X_POS, Y_POS;
	int T, trials;
	printf("Enter seed: (-1 to use system time)");
	n = scanf("%d", &s);
	if (n < 1)
	{
		printf("Could not read input\n");
		do
		{
			scanf("%c", &j);
		} while (j != '\n');
	}
	if (s == -1)
	{
		srand(time(0));
	}
	else
	{
		srand(s);
		printf("City size in X, Y: ");
		scanf("%d %d", &X, &Y);											// city size
	}
	if (X >= 2 && X <= 10 && Y >= 2 && Y <= 10)							//The process to find the staring point begin, if the city size is correct.
	{
		printf("Starting position (X Y): ");
		scanf("%d %d", &X_POS, &Y_POS);									//Starting position
	}
	else 																//The process to find the error begin, if the city size is incorrect.
	{
		if (X < 2 || X > 10)											// if the X-dimension was out of boundaries, a error message will appear.
			printf("X blocks must be >= 2 and <= 10\n");
		if (Y < 2 || Y > 10)											// if the Y-dimension was out of boundaries, a error message will appear.
			printf("Y blocks must be >= 2 and <= 10\n");
	}
	if (X_POS < 1 || X_POS >(X - 1) || Y_POS < 1 || Y_POS >(Y - 1))		//if the starting positions are incorrect, the process to find the error begin.
	{
		if (X_POS < 1 || X_POS >(X - 1))
			printf("Starting X position must satisfy (1 <= X <= %d)\n", (X - 1));
		if (Y_POS < 1 || Y_POS >(Y - 1))
			printf("Starting Y position must satisfy (1 <= Y <= %d)\n", (Y - 1));
	}
	else																// if X and Y are correct, the process to find the number of trials begin.
	{
		printf("Number of trials: ");									// number of trials
		scanf("%d", &T);
		if (T < 1 || T > 10);
		printf("Number of trials must be > 0 and <= 10\n");					//Error-checking
		if (T >= 1 && T <= 10)
		{
			for (trials = 0; trials != T; trials = trials + 1)
			{
				printf("Trial # %d \n", (trials + 1));
				int x = (rand() % X) + 1;
				int y = (rand() % Y) + 1;
				if (x == (X_POS - 1))
					printf("West: %d %d\n", x, y);
				if (x == (X_POS + 1))
					printf("East: %d %d\n", x, y);
				if (y == (Y_POS - 1))
					printf("South: %d %d\n", x, y);
				if (y == (Y_POS + 1))
					printf("North: %d %d\n", x, y);
			}
		}
	}
	return 0;
}
