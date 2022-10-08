#include <stdio.h>

void swap(int* a, int* b);
int select(int* s, int n, int k);

void main()
{
	int s[9] = {100, 50, 20, 10, 5, 4, 12, 1, 2};

	// Swap test
	//printf("%d | %d\n", s[1], s[2]);
	//swap(&s[1], &s[2]);
	//printf("%d | %d", s[1], s[2]);

	int ans = select(s, ceil(sizeof(s) / sizeof(int)), (sizeof(s) / sizeof(int)) / 2);
	printf("%d", ans);
}

int select(int* s, int n, int k)
{
	for (int i = 0; i < k; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < n; j++)
			if (s[j] < s[minIndex])
				minIndex = j;

		swap(&s[minIndex], &s[i]);
	}
	return s[k-1];
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}