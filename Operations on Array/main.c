#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *array = NULL;
int size = 0, s = 0;

void display() {
    int i = 0;
    for (; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

void insert() {
    int item = 0, loc = 0, j = size;
    if (size == s) {
        printf("Array already full.\n!!!!!!Overflow!!!!!\n");
        return;
    }
    printf("Enter the element to be inserted in the array:\t");
    scanf("%d", &item);
	do {
		printf("Enter the location where %d is to be inserted in the array:\t", item);
		scanf("%d", &loc);
		if (loc < 1 || loc > size + 1)
			printf("!!!Location out of bounds!!!\n");
	} while (loc < 1 || loc > size + 1);
    while (j >= loc - 1) {
        array[j + 1] = array[j];
        j--;
    }
    array[loc - 1] = item;
    ++size;
    printf("Element inserted.\n");
}

void delete() {
    int loc = 0, j = 0;
    if (size == 0) {
        printf("Array is empty.\n!!!!!Underflow!!!!!\n");
        return;
    }
    printf("Enter the location from where the element is to be deleted:\t");
    scanf("%d", &loc);
    if (loc < 1 || loc > s) {
        printf("!!!The entered location is out of bound!!!\n");
        return;
    }
    j = loc - 1;
    printf("Item %d deleted from location %d.\n", array[j], loc);
    while (j < size - 1) {
        array[j] = array[j + 1];
        j++;
    }
    --size;
}

void linear() {
    int item = 0, i = 0, j = 0;
    printf("Enter the element to be searched:\t");
    scanf("%d", &item);
    for (; i < size; ++i) {
        if (array[i] == item) {
            printf("The required element is found at %dth position\n", i + 1);
            ++j;
        }
    }
    if (j == 0) {
        printf("\n!!!Element Not Found!!!\n");
    }
}

void binary() {
    int item = 0, beg = 0, last = size - 1, mid, x = 0, my = 0, i=0, j=0, tmp=0, ans = 0;
    printf("For binary search, the array has to be sorted. Do you want to sort the array?");
    printf("\nEnter 0 to cancel sorting or any other key to continue:\t");
    scanf("%d", &ans);
	if (ans == 0) {
		printf("!!!Binary search can't be performed!!!");
		return;
	}
	for (; i < size; ++i) {
		for (j = 0; j < size - 1; ++j, --i) {
			if (array[j] > array[j + 1]) {
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
    printf("Enter the element to be searched:\t");
    scanf("%d", &item);
    while (beg <= last) {
        mid = (beg + last) / 2;
        if (array[mid] == item) {
            printf("\nThe required element is found at %dth position", mid + 1);
            ++x;
            my = mid;
            while (array[my - 1] == item && (my - 1) >= 0) {
                printf("\nThe required element is found at %dth position", my--);
            }
            while (array[mid + 1] == item && (mid + 1) < size) {
                printf("\nThe required element is found at %dth position", (mid++) + 2);
            }
            break;
        } else if (item > array[mid])
            beg = mid + 1;
        else
            last = mid - 1;
    }
    if (x == 0) {
        printf("\n!!!Element Not Found!!!\n");
    }
    printf("\n");
}

void menu() {
    printf("================================================================================");
    printf("\n**************************************MENU**************************************\n");
    printf("================================================================================");
    printf("\n1. Insertion");
    printf("\n2. Deletion");
    printf("\n3. Search For A Given Element From The Array Using Linear Search");
    printf("\n4. Search For A Given Element From The Array Using Binary Search");
    printf("\n5. Display Resultant Array");
    printf("\n0. Exit");
}

void choice() {
	int choice;
	do {
		printf("\nEnter Your Choice:\t");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 5);
	switch (choice) {
	case 1: insert();
			break;
	case 2: delete();
			break;
	case 3: linear();
			break;
	case 4: binary();
			break;
	case 5: display();
			break;
	case 0: exit(0);
			break;
	default:
		;
	}
}

int main(void) {
    printf("Enter the number of elements in the array:\t");
    scanf("%d", &s);
    array = (int*) malloc(s * sizeof(int));
    while (1) {
        menu();
        choice();
    }
    return EXIT_SUCCESS;
}
