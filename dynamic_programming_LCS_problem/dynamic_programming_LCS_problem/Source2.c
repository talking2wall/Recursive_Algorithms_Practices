#include <stdio.h>
#include <stdlib.h>

int** create_arr(int m, int n);
void print_arr_with_letters(int** arr, char* x, char* y, int m, int n);
int LCS(int** arr, char* x, char* y, int m, int n);
void lcs_retrieve_solution(int** arr, char* x, char* y, int m, int n);

int main()
{
	char x[] = { 'B', 'D', 'C', 'A', 'B', 'A' }; // 6
	char y[] = { 'A', 'B', 'C', 'B', 'D', 'A', 'B' }; // 7
	
	// Create two-dim array (m+1,n+1) filled with zeroes
	int** arr = create_arr(sizeof(x), sizeof(y));

	// print array before fillment
	print_arr_with_letters(arr, x, y, sizeof(x), sizeof(y));

	// call LCS algorithm
	printf("\n");
	printf("%d\n", LCS(arr, x, y, sizeof(x), sizeof(y)));
	printf("\n");

	// print array after fillment
	print_arr_with_letters(arr, x, y, sizeof(x), sizeof(y));
	printf("\n");

	// retrieve one of the solutions
	lcs_retrieve_solution(arr, x, y, sizeof(x), sizeof(y));
}

void lcs_retrieve_solution(int** arr, char* x, char* y, int m, int n)
{
	if (m == 0 || n == 0)
		return;

	if (x[m - 1] == y[n - 1])
	{
		lcs_retrieve_solution(arr, x, y, m - 1, n - 1);
		printf("%c ", y[n - 1]);
	}
	else if (arr[m - 1][n] >= arr[m][n - 1])
	{
		lcs_retrieve_solution(arr, x, y, m - 1, n);
	}
	else
	{
		lcs_retrieve_solution(arr, x, y, m, n - 1);
	}
}

int LCS(int** arr, char* x, char* y, int m, int n)
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	return arr[m][n];
}

int** create_arr(int m, int n)
{
	int** arr = (int**)calloc(m + 1, sizeof(int*));

	for (size_t i = 0; i <= n; i++)
		arr[i] = (int*)calloc(n + 1, sizeof(int));

	return arr;
}

void print_arr_with_letters(int** arr, char* x, char* y, int m, int n)
{
	printf("          "); // each char takes 5 spaces, then we skip y

	for (size_t i = 0; i < n; i++)
	{
		printf("  %c  ", y[i]);
	}

	printf("\n");

	for (size_t i = 0; i <= m; i++)
	{
		if (i > 0)
			printf("  %c  ", x[i - 1]);
		else
			printf("     ");

		for (int j = 0; j <= n; j++)
		{
				printf("  %d  ", arr[i][j]);
		}

		printf("\n");
	}
}