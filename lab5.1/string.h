#pragma once

#include"Header.h"
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

//typedef struct
//{
//
//	char* data;
//	int lenght;
//
//	/*String() {
//		data = new char;
//		*data = '\0';
//		lenght = 0;
//		printf("\nmade empty\n");
//	}
//
//	String(char* copy) {
//		int i;
//		lenght = 0;
//		while (*(copy + lenght) != '\0') {
//			lenght = lenght + 1;
//		}
//		data = new char[lenght + 1];
//		for (i = 0; i < lenght + 1; i++) {
//			data[i] = copy[i];
//		}
//		printf("\nmade char*\n");
//	}
//
//	String(String& copy)
//	{
//		int i;
//		lenght = copy.lenght;
//		data = new char[lenght + 1];
//		for (i = 0; i < lenght + 1; i++) {
//			data[i] = copy.data[i];
//		}
//		printf("\ncopy\n");
//	}
//
//	~String()
//	{
//		delete data;
//		printf("\ndelete\n");
//	}
//
//	String& operator=(String& orig)
//	{
//		int i;
//		lenght = orig.lenght;
//		data = new char[lenght + 1];
//		for (i = 0; i < lenght + 1; i++) {
//			data[i] = orig.data[i];
//		}
//		printf("\n=\n");
//		return *this;
//	}
//
//	operator const char* () const {
//		printf("\nconst char *\n");
//		return (const char*)data;
//	}
//
//	String& operator+=(String& orig)
//	{
//		printf("\n+=\n");
//		if (orig.lenght > 0) {
//			char* word;
//			int i;
//			word = data;
//			data = new char[lenght + orig.lenght + 1];
//			for (i = 0; i < lenght; i++) {
//				data[i] = word[i];
//			}
//			for (i = lenght; i <= (lenght + orig.lenght); i++) {
//				data[i] = orig.data[i - lenght];
//			}
//			lenght = lenght + orig.lenght;
//			delete word;
//		}
//		return *this;
//	}
//
//	String& operator+(String& second) const
//	{
//		printf("\n+\n");
//		String* result;
//		result = new String;
//		result->lenght = lenght + second.lenght;
//		result->data = new char[result->lenght + 1];
//		int i;
//		if (lenght > 0) {
//			for (i = 0; i < lenght; i++) {
//				result->data[i] = data[i];
//			}
//		}
//		if (second.lenght > 0) {
//			for (i = lenght; i < result->lenght; i++) {
//				result->data[i] = second.data[i - lenght];
//			}
//		}
//		result->data[result->lenght] = '\0';
//		return *result;
//		delete result;
//	}
//
//	char operator[](const int index) const
//	{
//		printf("\noperator[] const\n");
//		if (index >= 0 && index < lenght) {
//			return data[index];
//		}
//		else throw "incorrect index";
//	}
//
//	char& operator[](const int index)
//	{
//		printf("\noperator[]\n");
//		if (index >= 0 && index < lenght) {
//			return data[index];
//		}
//		else throw "incorrect index";
//
//	}*/
//} String;