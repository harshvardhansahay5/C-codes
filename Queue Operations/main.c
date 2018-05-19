#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size, *array;

void insert() {
	if (rear == (size - 1)) {
		printf("!!!!OVERFLOW!!!!\n");
	} else if (rear == -1) {
		front = rear = 0;
		printf("Enter The Element To Be Inserted:");
		scanf("%d", &array[rear]);
		printf("Element Inserted\n");
	} else {
		rear++;
		printf("Enter The Element To Be Inserted:");
		scanf("%d", &array[rear]);
		printf("Element Inserted\n");
	}

}

void delete() {
	if (front == -1) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		printf("The Element %d is Deleted\n", array[front]);
		if (front == rear)
			front = rear = -1;
		else
			front++;
	}
}

void display() {
	int p;
	if (front == -1) {
		printf("!!!!NO Element Inserted!!!!\n");
	} else {
		p = front;
		for (; p < rear; ++p)
			printf("%d->", array[p]);
		printf("%d", array[p]);
		printf("\n");
	}

}

void menu() {
	printf("================================================================================");
	printf("\n**************************************MENU**************************************\n");
	printf("================================================================================");
	printf("\n1. To Insert An Element In The Queue");
	printf("\n2. To Delete An Element From The Queue");
	printf("\n3. Display The Queue");
	printf("\n0. Exit");
}

void choice() {
	int choice;
	do {
		printf("\nEnter Your Choice:\t");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 3);
	switch (choice) {
	case 1: insert();
			break;
	case 2: delete();
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
	printf("Enter the maximum number of elements in the queue:\t");
	scanf("%d", &size);
	array = (int*) malloc(size * sizeof(int));
	while (1) {
		menu();
		choice();
	}
	return EXIT_SUCCESS;
}
