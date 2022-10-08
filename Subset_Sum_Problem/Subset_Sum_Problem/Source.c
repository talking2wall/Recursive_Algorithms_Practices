#include <stdio.h>
#include <stdlib.h>

int** create_table(int n, int m);
void print_arr(int** arr, int n, int m);
int Subset_Sum(int** arr, int* A, int n, int s);
void retrieve_solution(int** arr, int* A, int n, int s);

void main()
{
	int* A = (int*)malloc(7 * sizeof(int));
	A = (int[6]){ 2, 1, 13, 5, 3, 21 };
	int n = 6;
	int possible_s = 16;
	int impossible_s = 12;

	int** arr = create_table(n, possible_s);

	printf("Table before fillment:\n");
	print_arr(arr, n, possible_s);

	printf("\nAnswer for %d = %s", possible_s, (Subset_Sum(arr, A, n, possible_s) ? "true" : "false"));
	printf("\nTable After fillment:\n");
	print_arr(arr, n, possible_s);
	printf("Solution Retrieval for %d:\n", possible_s);
	retrieve_solution(arr, A, n, possible_s);
	printf("\b\b= %d", possible_s);

	printf("\n");
	arr = create_table(n, impossible_s);
	printf("\nAnswer for %d = %s", impossible_s, (Subset_Sum(arr, A, n, impossible_s) ? "true" : "false"));
	printf("\nTable After fillment:\n");
	print_arr(arr, n, impossible_s);
}

void retrieve_solution(int** arr, int* A, int n, int s)
{
	if (n == 0 || s == 0)
		return;

	if (arr[n - 1][s] == 1)
	{
		retrieve_solution(arr, A, n - 1, s);
	}
	else
	{
		printf("%d + ", A[n-1]);
		retrieve_solution(arr, A, n - 1, s - A[n-1]);
	}
}

int Subset_Sum(int** arr, int* A, int n, int s)
{
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= s; j++)
		{
			if (A[i - 1] > j)
				arr[i][j] = arr[i - 1][j];
			else
				arr[i][j] = max(arr[i - 1][j],arr[i - 1][j - A[i - 1]]);
		}
	}

	return arr[n][s];
}

void print_arr(int** arr, int n, int m)
{
	n++;
	m++;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}

int** create_table(int n, int m)
{
	n++;
	m++;

	int** arr = (int**)calloc(n, sizeof(int*));

	for (size_t i = 0; i < n; i++)
		arr[i] = (int*)calloc(m, sizeof(int));
	
	for (size_t i = 0; i < n; i++)
		arr[i][0] = 1;
	
	return arr;
}