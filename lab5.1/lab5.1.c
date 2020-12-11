#include"string.h"
#include<stdio.h>
#include<string.h>

//typedef struct test
//{
//	int a;
//	int b;
//	char c;
//};

int main()
{
	char* test_1 = read_line();
	int test_compare = -2;

	printf("test_1: .%s.\n", test_1);

	char* test_2 = read_line();
	printf("test_2: .%s.\n", test_2);

	printf("concat(test_1, test_2): .%s.\n", concat(test_1, test_2));
	printf("concat(test_1, test_1): .%s.\n", concat(test_1, test_1));
	printf("concat(test_2, test_2): .%s.\n", concat(test_2, test_2));

	char* test_3;
	while (1)
	{
		test_1 = read_line();
		test_2 = read_line();
		test_3 = strstr(test_1, test_2);
		printf("strstr: .%s.\n", test_3);

		test_1 = read_line();
		test_2 = read_line();
		test_compare = ñompare(test_1, test_2);
		printf("test_1: %s, test_2: %s, compare = %d\n", test_1, test_2, test_compare);

		test_1 = read_line();
		test_2 = read_line();
		test_compare = index_of(test_1, test_2);
		printf("test_1: %s, test_2: %s, index_of = %d\n", test_1, test_2, test_compare);
	}

	return 0;
}