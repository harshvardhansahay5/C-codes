#include <stdio.h>
#include <stdlib.h>

struct stack {
	int info;
	struct stack *ptr;
}*top = NULL;

void push() {
	struct stack *nptr = (struct stack*) malloc(sizeof(struct stack));
	printf("Enter Info:\t");
	scanf("%d", &nptr->info);
	printf("New Element Inserted\n");
	nptr->ptr = NULL;
	if (top == NULL)
		top = nptr;
	else {
		nptr->ptr = top;
		top = nptr;
	}
}
void pop() {
	struct stack *nptr;
	if (top == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		nptr = top;
		top = top->ptr;
		printf("The Element With info %d is Deleted\n", nptr->info);
		free(nptr);
	}
}
void display() {
	struct stack *nptr;
	if (top == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		printf("\nThe Elements In The Stack Are\n");
		for (nptr = top; nptr != NULL; nptr = nptr->ptr)
			printf("%d\n", nptr->info);
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
