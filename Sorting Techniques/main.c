#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *array = NULL;
int size = 0;

void display() {
	int i = 0;
	for (; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void insert() {
	int i = 0;
	for (; i < size; ++i) {
		printf("Enter the %dth element:\t", i + 1);
		scanf("%d", &array[i]);
	}
	printf("\n");
	display();
}

void bubble_sort() {
	int i, j;
	for (i = 0; i < size - 1; ++i) {
		for (j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				array[j] = array[j] + array[j + 1];
				array[j + 1] = array[j] - array[j + 1];
				array[j] = array[j] - array[j + 1];
			}
			printf("Pass %d:\t", i+1+j);
					display();
		}
		usleep(150000);
		printf("Pass %d:\t", i+1);
		display();
	}
}

void insertion_sort() {
	int i, temp, j;
	for (i = 1; i < size; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = temp;
		usleep(150000);
		printf("Pass %d:\t", i);
		display();
	}
}

void selection_sort() {
	int i, j, min_idx, tmp;
	for (i = 0; i < size - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		tmp = array[min_idx];
		array[min_idx] = array[i];
		array[i] = tmp;
		usleep(150000);
		printf("Pass %d:\t", i+1);
		display();
	}
}

int partition(int low, int high) {
	int pivot = array[high], tmp;
	static int x;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (array[j] <= pivot) {
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	usleep(150000);
	printf("Pass %d:\t", ++x);
	display();
	return (i + 1);
}

void quick_sort(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);
		quick_sort(low, pi - 1);
		quick_sort(pi + 1, high);
	}
}

void menu() {
    printf("================================================================================");
    printf("\n**************************************MENU**************************************\n");
    printf("================================================================================");
    printf("\n1. Insertion of the whole array");
    printf("\n2. Bubble Sort");
    printf("\n3. Insertion Sort");
    printf("\n4. Selection Sort");
    printf("\n5. Quick Sort");
    printf("\n6. Display Resultant Array");
    printf("\n0. Exit");
}

void choice() {
	int choice;
	do {
		printf("\nEnter Your Choice:\t");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 6);
	switch (choice) {
	case 1: insert();
			break;
	case 2: bubble_sort();
			break;
	case 3: insertion_sort();
			break;
	case 4: selection_sort();
			break;
	case 5: quick_sort(0, size-1);
			break;
	case 6: display();
			break;
	case 0: exit(0);
			break;
	default:
		;
	}
}

int main(void) {
    printf("Enter the number of elements in the array:\t");
    scanf("%d", &size);
    array = (int*) malloc(size * sizeof(int));
    while (1) {
        menu();
        choice();
    }
    return EXIT_SUCCESS;
}
