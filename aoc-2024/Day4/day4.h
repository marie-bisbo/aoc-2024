#ifndef DAYFOUR_H
#define DAYFOUR_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LENGTH 140
#define LINE_LENGTH_SQUARED 19600

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
		if (((i - (2 * LINE_LENGTH)) > -1) && (((i % LINE_LENGTH) - 2) > -1))
		{
			if (letters[i] == 'M' && letters[i - (LINE_LENGTH) - 1] == 'A' && letters[i - (2 * LINE_LENGTH) - 2] == 'S')
			{
				char first = letters[i - 2];
				char second = letters[i - (2 * LINE_LENGTH)];
				if ((first == 'M' && second == 'S') || (first == 'S' && second == 'M'))
				{
					xmasCounter++;
				}
			}
		}

		if (((i + (2 * LINE_LENGTH)) < LINE_LENGTH_SQUARED) && (((i % LINE_LENGTH) + 2) < LINE_LENGTH))
		{
			if (letters[i] == 'M' && letters[i + LINE_LENGTH + 1] == 'A' && letters[i + (2 * LINE_LENGTH) + 2] == 'S')
			{
				char first = letters[i + 2];
				char second = letters[i + (2 * LINE_LENGTH)];
				if ((first == 'M' && second == 'S') || (first == 'S' && second == 'M'))
				{
					xmasCounter++;
				}
			}
		}
	}

	free(letters);

	printf("File found!\n");
	printf("XMAS counter: %d\n", xmasCounter);

	return;
}

#endif

