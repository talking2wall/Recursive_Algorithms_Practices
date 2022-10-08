//#include <stdio.h>
//#include <stdlib.h>
//
//int LCS(char* x, int m, char* y, int n);
//int LCS_ITTER(char* x, int m, char* y, int n);
//int** init_arr(int m, int n);
//void lcs_retrieve_solution(char* x, char* y, int i, int j);
//
//int c = 0;
//int** arr = NULL;
//
//int main()
//{
//	char x[] = { 'B', 'D', 'C', 'A', 'B', 'A' }; // 6
//	char y[] = { 'A', 'B', 'C', 'B', 'D', 'A', 'B' }; // 7
//
//	//arr = (int*)malloc(sizeof(int) * 7);
//	//printf("%d\n", LCS(x, 0, y, 0));
//	//printf("%d\n", LCS_O_of_MN(x, 7, y, 6));
//	//printf("%d", c);
//
//	arr = init_arr(6, 7); // init array matrix in size of (m + 1, n + 1)
//
//	for (size_t i = 0; i <= 6; i++)
//	{
//		for (size_t j = 0; j <= 7; j++)
//		{
//			printf("%d\t", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	printf("\n");
//	printf("%d\n", LCS_ITTER(x, 6, y, 7));
//	printf("\n");
//
//	for (size_t i = 1; i <= 7; i++)
//	{
//		arr[0][i] = y[i - 1];
//	}
//
//	for (size_t i = 1; i <= 6; i++)
//	{
//		arr[i][0] = x[i - 1];
//	}
//
//	for (size_t i = 0; i <= 6; i++)
//	{
//		for (size_t j = 0; j <= 7; j++)
//		{	
//			if (j == 0 || i == 0)
//				printf("%c\t", arr[i][j]);
//			else
//				printf("%d\t", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	printf("\n");
//
//	lcs_retrieve_solution(x, y, 6, 7);
//}
//
//int** init_arr(int m, int n)
//{
//	int** arr = (int**)calloc((m + 1), sizeof(int*));
//
//	for (int i = 0; i <= m; i++)
//		arr[i] = (int*)calloc((n + 1), sizeof(int));
//
//	return arr;
//}
//
//void lcs_retrieve_solution(char* x, char* y, int i, int j)
//{
//	if (i == 0 || j == 0)
//		return;
//
//	if (arr[i - 1][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 1])
//	{
//		lcs_retrieve_solution(x, y, i, j - 1);
//		//printf("%c, ", y[j - 1]);
//	}
//	else if (arr[i - 1][j] == arr[i][j - 1])
//	{
//		lcs_retrieve_solution(x, y, i - 1, j - 1);
//		printf("%c, ", y[j]);
//	}
//	else if (arr[i][j - 1] > arr[i - 1][j])
//	{
//		lcs_retrieve_solution(x, y, i, j - 1);
//	}
//	else
//	{
//		lcs_retrieve_solution(x, y, i - 1, j);
//	}
//
//	
//}
//
//int LCS_ITTER(char* x, int m, char* y, int n)
//{
//	//for (int i = 1; i <= m; i++)
//	//{
//	//	for (int j = 1; j <= n; j++)
//	//	{
//	//		if (x[i] == y[j])
//	//			arr[i][j] = arr[i - 1][j - 1] + 1;
//	//		else
//	//			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
//	//	}
//	//}
//
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (x[i] == y[j])
//				arr[i][j] = arr[i - 1][j - 1] + 1;
//			else if (arr[i - 1][j] >= arr[i][j - 1])
//				arr[i][j] = arr[i - 1][j];
//			else
//				arr[i][j] = arr[i][j - 1];
//		}
//	}
//
//	return arr[m][n];
//}
//
//int LCS(char* x, int m, char* y, int n)
//{
//	c++;
//
//	if (m == -1 || n == -1)
//		return 0;
//
//	if (x[m] == y[n])
//	{
//		return LCS(x, m - 1, y, n - 1) + 1;
//	}
//	else
//		return max(LCS(x, m - 1, y, n), LCS(x, m, y, n - 1));
//}