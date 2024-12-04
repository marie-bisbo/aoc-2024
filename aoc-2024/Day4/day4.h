#ifndef DAYFOUR_H
#define DAYFOUR_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LENGTH 10
#define LINE_LENGTH_SQUARED 100

void GetResult()
{
	FILE* fptr;
	fopen_s(&fptr, "C:/Dev/aoc-2024/aoc-2024/Day4/day4_data.txt", "r");

	if (fptr == NULL)
	{
		printf("File not found!\n");

		return;
	}

	char* letters = malloc(LINE_LENGTH_SQUARED + 1);
	if (letters == NULL)
	{
		return;
	}

	for (int i = 0; i < LINE_LENGTH_SQUARED + 1; i++)
	{
		letters[i] = '\0';
	}

	int counter = 0;
	int c = 0;
	while (counter < LINE_LENGTH_SQUARED)
	{
		c = fgetc(fptr);
		if ((c != EOF) && (c != '\n') && (c != '\0'))
		{
			letters[counter++] = (char)c;
		}
	}

	int xmasCounter = 0;
	for (int i = 0; i < LINE_LENGTH_SQUARED; i++)
	{
		if (letters[i] != 'X')
		{
			continue;
		}

		if (i - 3 > -1)
		{
			if (letters[i - 1] == 'M' && letters[i - 2] == 'A' && letters[i - 3] == 'S')
			{
				xmasCounter++;
			}
		}
		if (i + 3 < LINE_LENGTH_SQUARED)
		{
			if (letters[i + 1] == 'M' && letters[i + 2] == 'A' && letters[i + 3] == 'S')
			{
				xmasCounter++;
			}
		}
		if ((i - (3 * LINE_LENGTH)) > -1)
		{
			if (letters[i - LINE_LENGTH] == 'M' && letters[i - (2 * LINE_LENGTH)] == 'A' && letters[i - (3 * LINE_LENGTH)] == 'S')
			{
				xmasCounter++;
			}
		}
		if ((i + (3 * LINE_LENGTH)) < LINE_LENGTH_SQUARED)
		{
			if (letters[i + LINE_LENGTH] == 'M' && letters[i + (2 * LINE_LENGTH)] == 'A' && letters[i + (3 * LINE_LENGTH)] == 'S')
			{
				xmasCounter++;
			}
		}
		if ((i - (3 * LINE_LENGTH) - 3) > -1)
		{
			if (letters[i - LINE_LENGTH - 1] == 'M' && letters[i - (2 * LINE_LENGTH) - 2] == 'A' && letters[i - (3 * LINE_LENGTH) - 3] == 'S')
			{
				xmasCounter++;
			}
		}
		if ((i + (3 * LINE_LENGTH) + 3) < LINE_LENGTH_SQUARED)
		{
			if (letters[i + LINE_LENGTH + 1] == 'M' && letters[i + (2 * LINE_LENGTH) + 2] == 'A' && letters[i + (3 * LINE_LENGTH) + 3] == 'S')
			{
				xmasCounter++;
			}
		}
		if ((i - (3 * LINE_LENGTH) + 3) > -1)
		{
			if (letters[i - LINE_LENGTH + 1] == 'M' && letters[i - (2 * LINE_LENGTH) + 2] == 'A' && letters[i - (3 * LINE_LENGTH) + 3] == 'S')
			{
				xmasCounter++;
			}
		}
		if ((i + (3 * LINE_LENGTH) - 3) < LINE_LENGTH_SQUARED)
		{
			if (letters[i + LINE_LENGTH - 1] == 'M' && letters[i + (2 * LINE_LENGTH) - 2] == 'A' && letters[i + (3 * LINE_LENGTH) - 3] == 'S')
			{
				xmasCounter++;
			}
		}
	}

	free(letters);

	printf("File found!\n");
	printf("XMAS counter: %d\n", xmasCounter);

	return;
}

#endif

