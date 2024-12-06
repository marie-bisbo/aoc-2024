#ifndef DAYFIVE_H
#define DAYFIVE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Entry
{
	int value;
	int currentIndex;
	int valuesAfter[100];
} Entry;

void GetResult()
{
	FILE* fptr;
	fopen_s(&fptr, "C:/Dev/aoc-2024/aoc-2024/Day5/day5_data.txt", "r");

	if (fptr == NULL)
	{
		printf("File not found!\n");

		return;
	}

	char row[100] = { 0 };
	Entry entries[21];
	int currentEntryIndex = 0;
	int total = 0;
	for (int i = 0; i < 21; i++)
	{
		entries[i].value = 0;
		entries[i].currentIndex = 0;
	}

	bool secondPart = false;
	while (fgets(row, 100, fptr) != NULL)
	{
		if (row[0] == '\n')
		{
			secondPart = true;
			continue;
		}

		if (secondPart)
		{
			int middleNumber = 0;
			int numValues = 0;
			int values[10] = { 0 };

			char* ptr;
			char* next;
			ptr = strtok_s(row, ",", &next);
			while (ptr && ptr != '\n')
			{
				values[numValues++] = atoi(ptr);
				ptr = strtok_s(NULL, ",", &next);
			}

			int currentValue = 0;
			bool valid = false;
			while (values[currentValue] != 0)
			{
				Entry currentEntry = { 0 };
				for (int i = 0; i < 21; i++)
				{
					if (entries[i].value == values[currentValue])
					{
						currentEntry = entries[i];
						break;
					}
				}

				int after = currentValue + 1;
				while (values[after] != 0)
				{
					for (int i = 0; i < 100; i++)
					{
						if (currentEntry.valuesAfter[i] == values[after])
						{
							valid = true;
							break;
						}
					}
					after++;
				}

				if (!valid)
				{
					break;
				}
				else
				{
					valid = false;
				}
				currentValue++;
			}

			if (valid)
			{
				int valueToAdd = values[currentValue / 2];
				printf("Value to add: %d\n", valueToAdd);
				total += valueToAdd;
			}

			/*
			printf("Values: ");
			for (int i = 0; i < 10; i++)
			{
				printf("%d, ", values[i]);
			}
			printf("\n");
			*/
		}

		else
		{
			char* ptr;
			char* next;
			ptr = strtok_s(row, "|", &next);
			int tmpValue = atoi(ptr);
			ptr = strtok_s(NULL, "|", &next);
			bool added = false;
			for (int i = 0; i < currentEntryIndex + 1; i++)
			{
				if (entries[i].value == tmpValue)
				{
					entries[i].valuesAfter[entries[i].currentIndex] = atoi(ptr);
					entries[i].currentIndex++;
					added = true;
					break;
				}
			}

			if (!added)
			{
				Entry entry = { 0, 0 };
				entry.value = tmpValue;
				entry.valuesAfter[entry.currentIndex] = atoi(ptr);
				entry.currentIndex++;
				entries[currentEntryIndex] = entry;
				currentEntryIndex++;
			}
		}
	}

	/*
	for (int i = 0; i < 21; i++)
	{
		printf("Entry %d: ", entries[i].value);
		for (int j = 0; j < 100; j++)
		{
			printf("%d, ", entries[i].valuesAfter[j]);
		}
		printf("\n");
	}
	*/

	printf("Total: %d\n", total);
	printf("File found!\n");

	return;
}

#endif

