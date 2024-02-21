#include "sort.h"

/**
 * get_max - Gets the maximum value
 * Description: in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts array of integers in ascending order
 * DEscription: using the counting sort algorithm and prints
 * 		counting array after setting it up
 * @array: An array of integers
 * @size: The size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *counting, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	counting = malloc(sizeof(int) * (max + 1));
	if (counting == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		counting[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counting[i] += counting[i - 1];
	print_array(counting, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[counting[array[i]] - 1] = array[i];
		counting[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(counting);
}
