#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int Levenshtein_Distance_rec(char* X, char* Y);
int Levenshtein_Distance(int** arr, char* X, char* Y);
char* remove_last_c(char* X);
int** create_arr(int x, int y);
void print_arr(int** arr, int x, int y);
int min3(int num1, int num2, int num3);

void main()
{
	//char* word1 = "Saturday";
	//char* word2 = "Sunday";

	char* word1 = "writers";
	char* word2 = "vintner";

	char* X = (char*)malloc(sizeof(word1));
	char* Y = (char*)malloc(sizeof(word2));

	strcpy(X, word1);
	strcpy(Y, word2);

	printf("Recursive Solution: %d\n\n", Levenshtein_Distance_rec(X, Y));

	// iterative algorithm
	int** arr = create_arr(strlen(X), strlen(Y));

	printf("Iterative Solution: %d\n", Levenshtein_Distance(arr, X, Y));

	print_arr(arr, strlen(X), strlen(Y));
}

//void retrieve_solution(int** arr, char* X, char* Y, int i, int j)
//{
//	if (X[i] != Y[j]) // could be delete or insert
//	{
//		;
//	}
//	else // replace (skip)
//	{
//
//	}
//}

int Levenshtein_Distance(int** arr, char* X, char* Y)
{
	for (size_t i = 0; i <= strlen(X); i++)
	{
		for (size_t j = 0; j <= strlen(Y); j++)
		{
			if (i == 0)
				arr[i][j] = j;
			else if (j == 0)
				arr[i][j] = i;
			else if (X[i - 1] == Y[j - 1])
				arr[i][j] = min3(arr[i - 1][j] + 1, arr[i][j - 1] + 1, arr[i - 1][j - 1] + 0);
			else
				arr[i][j] = min3(arr[i - 1][j] + 1, arr[i][j - 1] + 1, arr[i - 1][j - 1] + 1);
		}
	}

	return arr[strlen(X)][strlen(Y)];
}

int Levenshtein_Distance_rec(char* X, char* Y)
{
	if (strlen(X) == 0 && strlen(Y) == 0)
	{
		return 0;
	}
	else if (strlen(X) == 0)
	{
		return Levenshtein_Distance_rec(X, remove_last_c(Y)) + 1;
	}
	else if (strlen(Y) == 0)
	{
		return Levenshtein_Distance_rec(remove_last_c(X), Y) + 1;
	}

	int c_replace = 1;

	if (X[strlen(X) - 1] == Y[strlen(Y) - 1])
		c_replace = 0;

	return min3(Levenshtein_Distance_rec(remove_last_c(X), remove_last_c(Y)) + c_replace,
			    Levenshtein_Distance_rec(remove_last_c(X), Y) + 1,
			    Levenshtein_Distance_rec(X, remove_last_c(Y)) + 1);
}

char* remove_last_c(char* X)
{
	if (strlen(X) == 0)
		return "\0";
	else
	{
		char* newStr = (char*)malloc(strlen(X));
		strcpy(newStr, X);
		newStr[strlen(X) - 1] = '\0';
		return newStr;
	}
}

int** create_arr(int x, int y)
{
	x++;
	y++;

	int** arr = (int**)calloc(x, sizeof(int*));

	for (size_t i = 0; i < x; i++)
		arr[i] = (int*)calloc(y, sizeof(int*));

	return arr;
}

void print_arr(int** arr, int x, int y)
{
	for (size_t i = 0; i <= x; i++)
	{
		for (size_t j = 0; j <= y; j++)
		{
			printf("  %d  ", arr[i][j]);
		}
		printf("\n");
	}
}

int min3(int num1, int num2, int num3)
{
	int minimum = min(num1, num2);
	minimum = min(minimum, num3);
	return minimum;
}