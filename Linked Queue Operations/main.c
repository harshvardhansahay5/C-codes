#include <stdio.h>
#include <stdlib.h>

struct queue {
	int info;
	struct queue *ptr;
}*front = NULL, *rear = NULL;

void insert() {
	struct queue *nptr = (struct queue*) malloc(sizeof(struct queue));
	printf("Enter Info:\t");
	scanf("%d", &nptr->info);
	printf("New Element Inserted\n");
	nptr->ptr = NULL;
	if (front == NULL)
		front = rear = nptr;
	else {
		rear->ptr = nptr;
		rear = nptr;
	}
}

void delete() {
	struct queue *nptr;
	if (front == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		nptr = front;
		front = front->ptr;
		printf("The Element %d is Deleted\n", nptr->info);
		free(nptr);
	}
}

void display() {
	struct queue *nptr;
	if (front == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		printf("The Elements In The QUEUE Are\n");
		for (nptr = front; nptr != NULL; nptr = nptr->ptr)
			printf("%d\n", nptr->info);
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
	default: ;
	}
}

int main(void) {
	while (1) {
		menu();
		choice();
	}
	return EXIT_SUCCESS;
}
