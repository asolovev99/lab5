#pragma once

#include"string_private.h"
#include<stdlib.h>
#include<stdio.h>

char* read_line()
{
	char symbol = '\0';
	char* result = (char*)malloc(sizeof(char));
	int length_of_result = 0;
	result[0] = '\0';

	//symbol = getchar();
	symbol = getchar();
	/*if (symbol != '\n')
	{
		result = (char*)realloc(result, sizeof(char) * 2);
		result[0] = symbol;
		result[1] = '\0';
		length_of_result++;
	}*/
	while (symbol != '\n')
	{
		result = (char*)realloc(result, sizeof(char) * (length_of_result + 2));
		result[length_of_result] = symbol;
		result[length_of_result + 1] = '\0';
		length_of_result++;

		symbol = getchar();
	}

	return result;
}

int length(char* value)
{
	int result = 0;

	if (value == NULL)
	{
		return 0;
	}

	while (value[result] != '\0')
	{
		result++;
	}

	return result;
}

char* concat(char* left, char* right)
{
	int lenght_of_left = length(left);
	int lenght_of_right = length(right);
	char* result = (char*)malloc(sizeof(char) * (lenght_of_left + lenght_of_right + 1));

	for (int i = 0; i < lenght_of_left; i++)
	{
		result[i] = left[i];
	}

	for (int i = lenght_of_left; i < lenght_of_left + lenght_of_right; i++)
	{
		result[i] = right[i - lenght_of_left];
	}

	result[lenght_of_left + lenght_of_right] = '\0';

	return result;
}

int index_of(char* source, char* find)
{
	int lenght_source = length(source);
	int lenght_find = length(find);
	int is_find = 0;
	int i = 0;
	int j = 0;

	if (find == NULL)
	{
		//printf("");// NULL - пустая строка
		return 0;
	}
	else
	{
		i = 0;
		while (i + lenght_find <= lenght_source)
		{
			is_find = 1;
			for (j = i; (j < i + lenght_find) && is_find; j++)
			{
				if (source[j] != find[j - i])
				{
					is_find = 0;
				}
			}
			if (is_find) // Нашли
			{
				return i;
			}

			i++;
		}

		return -1; // Не нашли
	}
}

int сompare(char* left, char* right)
{
	int i = 0;

	if ((left == NULL) && (right == NULL))
	{
		return 0;
	}
	else if (left == NULL)
	{
		return '\0' - right[0];
	}
	else if (right == NULL)
	{
		return left[i] - '\0';
	}
	else
	{
		while ((left[i] == right[i]) && (left[i] != '\0') && (right[i] != '\0'))
		{
			i++;
		}

		return left[i] - right[i];
	}
}