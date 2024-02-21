#include "sort.h"

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
 * selection_sort - Sorts an array of integers in ascending order
 * Description: using the selection sort algorithm and prints the
 * array after each swap
 * @array: An array of integers
 * @size: The size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i; /* Assumes the current minimum */
			/* is the first element of the unsorted part*/
		for (j = i + 1; j < size; j++)
			minimum = (array[j] < *minimum) ? (array + j) : minimum;
		/*updates minimum if a samll element is found*/

		if ((array + i) != minimum)
		{
			swap_ints(array + i, minimum);
		/*swaps the minimum element with the first unsorted element*/
			print_array(array, size);/*prints array after each swap*/
		}
	}
}
