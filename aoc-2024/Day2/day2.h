#ifndef DAYTWO_H
#define DAYTWO_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void GetResult()
{
	FILE* fptr;
	fopen_s(&fptr, "C:/Dev/aoc-2024/aoc-2024/Day2/day2_data.txt", "r");

	if (fptr == NULL)
	{
		printf("File not found!\n");

		return;
	}

	char row[50];
	int safeReports = 0;
	while (fgets(row, 50, fptr) != NULL)
	{
		char* ptr;
		char* next;
		ptr = strtok_s(row, " ", &next);
		int previous = -1;
		int current = 0;
		bool safe = true;
		bool decreasing = false;
		bool increasing = false;
		while (ptr)
		{
			current = atoi(ptr);
			if (previous != -1)
			{
				if ((previous == current) || (abs(previous - current) > 3))
				{
					safe = false;
					break;
				}
				decreasing |= previous - current > 0;
				increasing |= previous - current < 0;
				if (decreasing && increasing)
				{
					safe = false;
					break;
				}
			}
			previous = current;
			ptr = strtok_s(NULL, " ", &next);
		}

		if (safe)
		{
			safeReports++;
		}
	}

	printf("Safe reports: %d\n", safeReports);

	printf("File found!\n");

	// printf("Result: %d\n", result);

	return;
}

#endif

