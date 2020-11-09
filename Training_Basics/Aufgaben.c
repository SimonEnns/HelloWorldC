#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

static int avgCounter = 0;
static double avgValue = 0;


// Aufgabe A34 (Betrag einer Zahl ermitteln)
float abs(float x) {
	return x < 0 ? -x : x;
}
void a34_betrag() {
	float x;
	printf("Enter a number: \n");
	scanf_s("%f", &x);

	float nx = abs(x);
	printf("The absolute value is [%.2f]\n", nx);

	a34_betrag();
}


// Aufgabe A37 (Fibonacci-Zahlen - recursive)
int fib(int n) {
	if (n == 1 || n == 2) return 1;
	return  fib(n - 1) + fib(n - 2);
}
void a37_fibonacci() {
	int n = 0;
	printf("How many fibonacci number would you like?");
	scanf_s("%i", &n);

	printf("Test: %i", fib(n));

	a37_fibonacci();
}

// Aufgabe A38 (Euclidischer Algorithmus)
int ggt(int a, int b) {
	if (a == b) return a;
	if (a > b) return ggt(a - b, b);
	if (a < b) return ggt(a, b - a);
}
void a38_euclid_ggt() {
	int a = 1;
	int b = 1;
	printf("Please enter two numbers:\n");
	scanf_s("%i%i", &a, &b);

	printf("ggt: %i\n", ggt(a, b));

	a38_euclid_ggt();
}

// Aufgabe A39 (recursive multiplication)
int getProduct(int a, int b) {
	if (a == 0 || b == 0) return 0;
	if (b > 0) return getProduct(a, b - 1) + a;
}
void a39_multiplication() {
	int a = 1;
	int b = 1;
	printf("Please enter two numbers:\n");
	scanf_s("%i%i", &a, &b);

	printf("Product of %i and %i: %i\n", a, b, getProduct(a, b));

	a39_multiplication();
}

// Aufgabe A40 (Potenzieren rekursiv)
double pow(double x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n > 1) return pow(x, n - 1) * x;
}
void a40_power() {
	double a = 1;
	int b = 1;
	printf("Please enter the number(double) and the exponent(int):\n");
	scanf_s("%lf%i", &a, &b);

	printf("%lf to the power of %i is: %lf\n", a, b, pow(a, b));

	a40_power();
}

// Aufgabe A41 (Zinsen)
double calcCapital(double c, double z, int t) {
	if (c == 0 || z == 0 || t <= 0) return c;
	if (t > 0) return calcCapital(c, z, t - 1) * (z / 100 + 1);
}
void a41_CalcCapital() {
	double c = 0, z = 0;
	int t = 0;

	printf("Please enter the start capital, the interestrate and the timeperiod in years:\n");
	scanf_s("%lf%lf%i", &c, &z, &t);

	printf("The final capital is: %lf\n", calcCapital(c, z, t));

	a41_CalcCapital();
}

// Aufgabe A42 (avg)
float avg(double x) {
	avgCounter++;
	avgValue += x;
	return avgValue / avgCounter;
}
void a42_average() {
	double x = 0;
	printf("Please enter a value:\n");
	scanf_s("%lf", &x);

	printf("The average of all entered values is: %lf\n", avg(x));

	a42_average();
}

// Aufgabe A43 (Groesse eines Arrays)
void a43_ArraySize() {
	int iarr[] = { 2,4,6,0,1,4,1,3,5,7 };
	double darr[] = { 3.311,4.1,5.0,6.87,9.99 };
	char str[] = "Hallo Welt";

	printf("INT - Size: %i, Elems: %i\n", sizeof(iarr), sizeof(iarr) / sizeof(iarr[0]));
	printf("DBL - Size: %i, Elems: %i\n", sizeof(darr), sizeof(darr) / sizeof(darr[0]));
	printf("STR - Size: %i, Elems: %i\n", sizeof(str), sizeof(str) / sizeof(str[0]));
}

// Aufgabe A44 (compare arrays)
int areEqual(int a[], int sizeA, int b[], int sizeB) {
	if (sizeA != sizeB)
		return -2;

	for (int i = 0; i < sizeA; i++)
		if (a[i] != b[i])
			return i;

	return -1;
}

void a44_CompareArrays() {
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 1, 2, 3, 4, 8 };
	int sizeA = sizeof(a) / sizeof(a[0]);
	int sizeB = sizeof(b) / sizeof(b[0]);

	printf("LengthA: %i\n", sizeA);
	printf("LengthB: %i\n", sizeB);
	printf("Result: %i\n", areEqual(a, sizeA, b, sizeB));
}

// Aufgabe A45 (Zeichen ersetzen)
void a45_ReplaceChar() {
	char chars[20];
	printf("Please enter some text (max. 9 chars)!\n");
	fgets(chars, 20, stdin);

	printf("Enter character to be replaced:\n");
	char replace = getchar();
	rewind(stdin); // empty input buffer
	printf("Enter substitution character:\n");
	char substitute = getchar();
	printf("Waiting for result...\n\n");

	printf("pre processed string: %s\n", chars);

	int i = 0;
	for (int i = 0; i <= sizeof(chars) / sizeof(chars[0]); i++)
		if (chars[i] == replace)
			chars[i] = substitute;

	printf("New string: %s", chars);

	a45_ReplaceChar();
}

// Aufgabe A46 (Palindrom)
void a46_Palindrome() {
	char text[21];
	bool isPalindrome = true;

	printf("Please enter some text (max. 20 chars)!");
	fgets(text, 21, stdin);

	int len = strlen(text) - 1; // -1: get rid of the appended '\n' char

	for (int i = 0; i < len; i++)
	{
		if (text[i] != text[len - i - 1]) // -1: get rid of '\0' char
		{
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome)
		printf("The text [%s] is a palindrome!\n", text);
	else
		printf("The text [%s] is NOT a palindrome!\n", text);

	a46_Palindrome();
}


// Aufgabe A47 (matrix transponieren)
void a47_TransposeMatrix() {
	int M[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} }, All[12], T[3][4];
	int x = sizeof(M) / sizeof(M[0]);
	int y = sizeof(M[0]) / sizeof(M[0][0]);

	// get values from old matrix
	int index = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			All[index] = M[i][j];
			index++;
		}
	}

	// get values in new matrix
	index = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			T[i][j] = All[index];
			index++;
		}
	}

	printf("\n--PRINT TRANSPOSED MATRIX--\n\n");

	for (int i = 0; i < sizeof(T) / sizeof(T[0]); i++)
	{
		for (int j = 0; j < sizeof(T[0]) / sizeof(T[0][0]); j++)
		{
			printf("RESULT[%i][%i]: %i\n", i, j, T[i][j]);
		}
	}
}