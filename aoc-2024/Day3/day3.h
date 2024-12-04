#ifndef DAYTHREE_H
#define DAYTHREE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void GetResult()
{
	FILE* fptr;
	fopen_s(&fptr, "C:/Dev/aoc-2024/aoc-2024/Day3/day3_data.txt", "r");

	if (fptr == NULL)
	{
		printf("File not found!\n");

		return;
	}

	char row[4000];
	unsigned long long total = 0;
	bool enabled = true;
	while (fgets(row, 4000, fptr) != NULL)
	{
		for (int i = 0; i < 4000; i++)
		{
			if (row[i] == '\0' || row[i] == '\n')
			{
				break;
			}

			if (row[i] == 'd' && row[i + 1] == 'o' && row[i + 2] == '(' && row[i + 3] == ')')
			{
				enabled = true;
			}
			else if (row[i] == 'd' && row[i + 1] == 'o' && row[i + 2] == 'n' && row[i + 3] == '\'' && row[i + 4] == 't' && row[i + 5] == '(' && row[i + 6] == ')')
			{
				enabled = false;
			}

			if (!enabled)
			{
				continue;
			}

			if (row[i] == 'm' && row[i + 1] == 'u' && row[i + 2] == 'l' && row[i + 3] == '(')
			{
				int tmp = i + 4;
				int counter = 0;
				char tmpStr[8] = { '\0' };
				char* ptr;
				char* next;
				while (counter < 8)
				{
					if (row[tmp] == ')')
					{
						int multiply = 1;
						ptr = strtok_s(tmpStr, ",", &next);
						while (ptr)
						{
							multiply *= atoi(ptr);
							ptr = strtok_s(NULL, ",", &next);
						}
						total += multiply;
						break;
					}
					tmpStr[counter] = row[tmp];
					tmp++;
					counter++;

					if (row[tmp] > '9' && row[tmp] != ',')
					{
						break;
					}
				}
			}
		}
	}

	printf("Total: %llu\n", total);

	printf("File found!\n");

	return;
}

#endif

