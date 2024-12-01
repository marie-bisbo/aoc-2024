#ifndef DAYONE_H
#define DAYONE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM_LINES 1000

int Compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void GetResult()
{
	FILE* fptr;
	fopen_s(&fptr, "C:/Dev/aoc-2024/aoc-2024/Day1/day1_data.txt", "r");

	if (fptr == NULL)
	{
		printf("File not found!\n");

		return;
	}

	int firstList[NUM_LINES] = { 0 };
	int secondList[NUM_LINES] = { 0 };

	int firstValue;
	int secondValue;
	int counter = 0;
	while (fscanf_s(fptr, "%d   %d", &firstValue, &secondValue) == 2)
	{
		printf("First value: %d, second value: %d\n", firstValue, secondValue);

		firstList[counter] = firstValue;
		secondList[counter] = secondValue;
		counter++;
	}

	qsort(firstList, NUM_LINES, sizeof(int), Compare);
	qsort(secondList, NUM_LINES, sizeof(int), Compare);

	int result = 0;
	for (int i = 0; i < NUM_LINES; i++)
	{
		int currentValue = firstList[i];
		int occurencesInSecondList = 0;
		for (int j = 0; j < NUM_LINES; j++)
		{
			if (secondList[j] == currentValue)
			{
				occurencesInSecondList++;
			}
		}
		result += occurencesInSecondList * currentValue;
	}

	printf("File found!\n");

	printf("Result: %d\n", result);

	return;
}

#endif

