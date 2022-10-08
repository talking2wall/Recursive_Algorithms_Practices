#include <stdio.h>

void swap(int* a, int* b);
int partition(int* arr, int low, int high);
void print_arr(int* arr, int n);
void quick_sort(int* arr, int low, int high);

int main()
{
	int arr[] = { 10, 80, 30, 90, 40, 50, 70, 17 };

	printf("Before quick sort:\n");
	print_arr(arr, 7);

	quick_sort(arr, 0, 6);

	printf("\nAfter quick sort:\n");
	print_arr(arr, 7);
}

void print_arr(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		printf("%d, ", arr[i]);

	printf("%d\n", arr[n-1]);
}

int a = 0;

void quick_sort(int* arr, int low, int high)
{
	a++;

	if (low < high)
	{
		int pivot = partition(arr, low, high);
		
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}

	printf("%d ", a);
}

int partition(int* arr, int low, int high)
{
	int pivot = high;
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= arr[pivot])
		{
			i++;
			swap(&arr[j], &arr[i]);
		}
	}

	swap(&arr[pivot], &arr[i + 1]);
	return i + 1;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}