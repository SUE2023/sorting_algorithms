#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turns a binary tree into a complete binary heap
 * Description: Turns a binary tree into a complete binary heap
 * @array: An array of integers representing a binary tree
 * @size: The size of the array/tree
 * @base: The index of the base row of the tree
 * @root: The root node of the binary tree
 * Return: void
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, big;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < base && array[left] > array[big])
		big = left;
	if (right < base && array[right] > array[big])
		big = right;

	if (big != root)
	{
		swap_ints(array + root, array + big);
		print_array(array, size);
		max_heapify(array, size, base, big);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * Description: using the heap sort algorithm - implementing the
 * 		sift-down heap sort and prints the array after each swap
 * @array: An array of integers
 * @size: The size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
