#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int benefit;
	int weight;
	struct item* next;
} item;

void print_list_items(item* head);
item* create_list(int* benefit, int* weight, int n);
int rec_knapsack_01(item* V, int k, int w);
int** create_arr(int k, int w);
int knapsack_01(int** arr, int benefit[5], int weight[5], int k, int w);
void print_arr(int** arr, int k, int w);
void knapsack_01_retreieve_solution(int** arr, int benefit[4], int weight[4], int k, int w);

void main()
{
	int benefit[] = { 3, 4, 5, 6 };
	int weight[] = { 2, 3, 4, 5 };

	item* head = create_list(benefit, weight, 4);

	print_list_items(head);

	// w = place left in bag
	// k = items from 0 to n
	printf("Max benefit recursion: %d", rec_knapsack_01(head, 4, 5));
	
	printf("\n");
	int** arr = create_arr(4, 5);
	printf("Max benefit iterations: %d", knapsack_01(arr, benefit, weight, 4, 5));
	printf("\nSolution matrix:");
	print_arr(arr, 4, 5);
	printf("Retrieved Solution:\n");
	knapsack_01_retreieve_solution(arr, benefit, weight, 4, 5);
}

void knapsack_01_retreieve_solution(int** arr, int benefit[4], int weight[4], int k, int w)
{
	if (k == 0 || w == 0)
		return;

	if (arr[k][w] == arr[k - 1][w])
	{
		knapsack_01_retreieve_solution(arr, benefit, weight, k - 1, w);
	}
	else
	{
		printf("%4d", k);
		knapsack_01_retreieve_solution(arr, benefit, weight, k - 1, w - weight[k-1]);
	}
}

int knapsack_01(int** arr, int benefit[4], int weight[4], int k, int w)
{
	for (size_t i = 1; i <= k; i++)
	{
		for (size_t j = 1; j <= w; j++)
		{
			if (weight[i - 1] <= j)
			{
				arr[i][j] = max(benefit[i - 1] + arr[i - 1][j - weight[i - 1]], arr[i - 1][j]);
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}
		}
	}

	return arr[k][w];
}

int rec_knapsack_01(item* V, int k, int w)
{
	if (k == 0 || w == 0)
		return 0;

	if (V->weight > w)
		return rec_knapsack_01(V->next, k-1, w);

	return max(rec_knapsack_01(V->next, k-1, w), rec_knapsack_01(V->next, k-1, w - V->weight) + V->benefit);
}

item* create_list(int* benefit, int* weight, int n)
{
	item* head = (item*)malloc(sizeof(item));
	head->benefit = benefit[0];
	head->weight = weight[0];
	head->next = NULL;

	item* temp = head;

	for (size_t i = 1; i < n; i++)
	{
		item* newItem = (item*)malloc(sizeof(item));
		newItem->benefit = benefit[i];
		newItem->weight = weight[i];
		newItem->next = NULL;

		temp->next = newItem;
		temp = temp->next;
	}

	return head;
}

void print_list_items(item* head)
{
	item* temp = head;
	printf("benefit : ");
	while (temp != NULL)
	{
		printf("%d, ", temp->benefit);
		temp = temp->next;
	}
	temp = head;
	printf("\nweight  : ");
	while (temp != NULL)
	{
		printf("%d, ", temp->weight);
		temp = temp->next;
	}
	printf("\n\n");
}

int** create_arr(int k, int w)
{
	k++;
	w++;

	int** arr = (int**)malloc(k * sizeof(int*));
	for (size_t i = 0; i < w; i++)
	{
		arr[i] = (int*)calloc(w, sizeof(int));
	}
	return arr;
}

void print_arr(int** arr, int k, int w)
{
	printf("\n");
	for (size_t i = 0; i <= k; i++)
	{
		for (size_t j = 0; j <= w; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}