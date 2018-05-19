#include <stdio.h>
#include <stdlib.h>

int top = -1, size, *array;

void push() {
	if (top == (size - 1)) {
		printf("!!!!OVERFLOW!!!!\n");
	} else {
		printf("Enter The Element To Be Inserted:");
		scanf("%d", &array[++top]);
		printf("Element Inserted\n");
	}
}

void pop() {
	if (top == -1) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		printf("The Element %d is Deleted\n", array[top--]);
	}
}

void display() {
	int p = top;
	if (top == -1) {
		printf("!!!!NO Element Inserted!!!!\n");
	} else {
		for(;p>0;--p)
		printf("%d->", array[p]);
		printf("%d", array[p]);
		printf("\n");
	}
}

void menu() {
	printf("================================================================================");
	printf("\n**************************************MENU**************************************\n");
	printf("================================================================================");
	printf("\n1. To PUSH An Element In The Stack");
	printf("\n2. To POP An Element From The Stack");
	printf("\n3. Display The Stack");
	printf("\n0. Exit");
}

void choice() {
	int choice;
	do {
		printf("\nEnter Your Choice:\t");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 3);
	switch (choice) {
	case 1: push();
			break;
	case 2: pop();
			break;
	case 3: display();
			break;
	case 0: exit(0);
			break;
	default:
		;
	}
}

int main(void) {
	printf("Enter the maximum number of elements in the stack:\t");
	scanf("%d", &size);
	array = (int*) malloc(size * sizeof(int));
	while (1) {
		menu();
		choice();
	}
	return EXIT_SUCCESS;
}
