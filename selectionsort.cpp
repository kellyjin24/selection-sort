#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void swap(int *, int *);
void selectionSort(int [], int);
void printSelection(int [], int);

int MAX_1 = 20;

int main() {
	int d1[MAX_1];
	
	// Initialize random seed
	srand(time(NULL));

// D[20]
	cout << "Generating first array of 20 random integers..." << endl;
	for (int i = 0; i < MAX_1; i++) {
		// Generate a random number between 0 and 200 for every new index
		int r = (rand() % 200) + 1;

		d1[i] = r;
	}

	// Display the array of 20 random integers
	cout << "D[20] = {";
	for (int i = 0; i < MAX_1; i++) {
		cout << d1[i] << ", ";

		if (i == MAX_1 - 1) {
			cout << d1[i] << "}";
			cout << endl;
		}
	}
	cout << endl;
	cout << endl;

	cout << "Performing selection sort..." << endl;
	selectionSort(d1, MAX_1);
	cout << "SORTED: D[20] = {";
	printSelection(d1, MAX_1);
	cout << endl;

	return 0;
}

void swap (int *a, int *b) {
	int temp = *a;

	*a = *b;
	*b = temp;
}

void selectionSort(int d[], int MAX) {
	int min_ida;

	// One by one, move boundary of unsorted subarray
	for (int i = 0; i < MAX - 1; i++) {
		
		// Find the min element in unsorted array
		min_ida = i;
		for (int j = i + 1; j < MAX; j++) {
			if (d[j] < d[min_ida]) {
				min_ida = j;
			}
		}
	
		// Swap the found minimum element with the first element
		swap(&d[min_ida], &d[i]);
	}
}
 
void printSelection(int d[], int MAX) {
	for (int i = 0; i < MAX; i++) {
		cout << d[i] << ", ";
	
		if (i == MAX - 1) {
			cout << d[i] << "}";
			cout << endl;
		}
	}
	cout << endl;
}
