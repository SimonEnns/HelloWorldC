#include <stdio.h>
#include <math.h>

// print an array
void printArr(int arr[], int length) {
	for (int i = 0; i < length; i++)
		printf("arr[%i]: \t%i\n", i, arr[i]);
}




/*******************
*
* SORTING ALGORITHMS
*
*******************/


/************
* BUBBLE SORT
*/
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

	printList(myList, length);
}



/***********
* MERGE SORT
*/
int b[100]; // <-- only a temporary solution

int merge(int A[], int l, int m, int r) {
	int l1, l2, i;

	for (i = l, l1 = l, l2 = m + 1; l1 <= m && l2 <= r; i++)
	{
		if (A[l1] <= A[l2])
			b[i] = A[l1++];
		else
			b[i] = A[l2++];
	}

	while (l1 <= m)
		b[i++] = A[l1++];
	while (l2 <= r)
		b[i++] = A[l2++];
	for (i = l; i <= r; i++)
		A[i] = b[i];
}

int mergeSort(int A[], int l, int r) {
	if (l < r)
	{
		int m = (l + r) / 2;

		mergeSort(A, l, m);
		mergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}
	else
	{
		return 0;
	}
}

void mergeSortHandler(int A[], int n) {
	mergeSort(A, 0, n - 1);
	printArr(A, n);
}
