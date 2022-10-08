//#include<stdio.h>
////To use realloc in our program
//#include<stdlib.h>
//
//int main()
//{
//    //int* ptr
//    int* ptr = (int[14]) { 32, 64, 66, 69, 72, 81, 87, 94, 95, 1, 2, 4, 8, 16 };
//
//    //allocating memory for 10 integers
//    ptr = malloc(10 * sizeof(int));
//
//    //realloc memory size to store only 5 integers
//    ptr = realloc(ptr, 5 * sizeof(int));
//
//    return 0;
//}
//
//
////#include <stdio.h>
////#include <string.h>
////#include <stdlib.h>
////
////void sort_arr(int* arr, int n);
////
////int main()
////{
////	int* arr[] = { 32, 64, 66, 69, 72, 81, 87, 94, 95, 1, 2, 4, 8, 16 };
////
////	sort_arr(arr, 14);
////
////	//free(arr);
////}
////
////void sort_arr(int* arr, int n)
////{
////	int first_arr_index = 0;
////	int second_arr_index = 0;
////
////	int i = 0;
////
////	while (i < n)
////	{
////		if (arr[i] > arr[i + 1])
////		{
////			second_arr_index = i + 1;
////			break;
////		}
////		i++;
////	}
////
////	int size_of_second_arr = n - second_arr_index;
////
////	int* arr2;
////	arr2 = realloc(arr, (n + size_of_second_arr) * sizeof(int));
////
////	//memcpy(arr + size_of_second_arr, arr, n - size_of_second_arr);
////
////	for (int i = 0; i < n + size_of_second_arr; i++)
////	{
////		printf("%d ", arr[i]);
////	}
////}