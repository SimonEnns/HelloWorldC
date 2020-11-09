#include <stdio.h>
#include "ALGORITHMEN.h"
#include "AUFGABEN.h"



void runListAlgorithm() {
	int A[] = { 43, 2, 48, 12, 102, 98, 12, 63, 87, 16, 110, 0, 1, 3, 4, 5, 6, 44, 42, 55, 81 };
	int n = sizeof(A) / sizeof(A[0]);

	//bubbleSort(A, len);
	//quickSort(A, 0, len);
	mergeSortHandler(A, n);
}

void main() {
	//a47_TransposeMatrix();
	//a48_Bubblesort();

	runListAlgorithm();
}