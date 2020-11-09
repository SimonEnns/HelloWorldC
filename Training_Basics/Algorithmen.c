#include <stdio.h>

void bubbleSort(int myList[], int length) {
	int bfr = 0;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (myList[j] > myList[j + 1])
			{
				bfr = myList[j];
				myList[j] = myList[j + 1];
				myList[j + 1] = bfr;
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		printf("%i: %i\n", i, myList[i]);
	}
}

void quickSort(int list[], int first, int last) {
	int i, j, pivot, tmp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while ((list[i] <= list[pivot]) && (i < last)) i++;
			while (list[j] > list[pivot]) j--;

			if (i < j)
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}

		tmp = list[pivot];
		list[pivot] = list[j];
		list[j] = tmp;

		quickSort(list, first, j - 1);
		quickSort(list, j + 1, last);
	}
}
