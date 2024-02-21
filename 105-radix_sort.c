#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

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
 * radix_counting_sort - Sorts the significant digits of an array of integers
 * desription: in ascending order using the counting sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * @sig: The significant digit to sort on
 * @buff: A buffer to store the sorted array
 * Return: void
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int counting;
	size_t i;

	counting[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
		counting[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		counting[i] += counting[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[counting[(array[i] / sig) % 10] - 1] = array[i];
		counting[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * Description: using the radix sort algorithm - implementing the LSD
 * 		radix sort algorithm and prints the array after each
 * 		each significant digit increase
 * @array: An array of integers
 * @size: The size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
