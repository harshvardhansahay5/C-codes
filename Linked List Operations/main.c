#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
}*start = NULL;

void insert_at_beg() {
	struct node *nptr = (struct node*) malloc(sizeof(struct node*));
	nptr->link = start;
	start = nptr;
	printf("Enter the element to be inserted:\t");
	scanf("%d", &start->info);
	printf("New Element Inserted\n");
}

void insert_at_end() {
	struct node *nptr = (struct node*) malloc(sizeof(struct node*)), *temp;
	if (!start) {
		insert_at_beg();
	}
	else {
		temp = start;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = nptr;
		printf("Enter the element to be inserted:\t");
		scanf("%d", &nptr->info);
		nptr->link = NULL;
		printf("New Element Inserted\n");
	}
}

void display_at_beg() {
	if (start == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		printf("Element at beginning is:\t%d\n", start->info);
	}
}

void delete_end() {
	struct node *temp;
	if (start == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else if (!start->link) {
		free(start);
		start = NULL;
	} else {
		temp = start;
		while (temp->link->link != NULL) {
			temp = temp->link;
		}
		printf("The Element %d is Deleted\n", temp->link->info);
		free(temp->link);
		temp->link = NULL;
	}
}

void display_op() {
	struct node *temp;
	if (start == NULL) {
		printf("!!!!UNDERFLOW!!!!\n");
	} else {
		temp = start;
		printf("The Elements In The LIST Are\n");
		while (temp != NULL) {
			printf("%d\n", temp->info);
			temp = temp->link;
		}
	}
}

void menu() {
    printf("================================================================================");
    printf("\n**************************************MENU**************************************\n");
    printf("================================================================================");
    printf("\n1. Insertion at beginning");
    printf("\n2. Insertion at end");
    printf("\n3. Display at beginning");
    printf("\n4. Deletion at end");
    printf("\n5. Display operation");
    printf("\n0. Exit");
}

void choice() {
	int choice;
	do {
		printf("\nEnter Your Choice:\t");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 5);
	switch (choice) {
	case 1: insert_at_beg();
			break;
	case 2: insert_at_end();
			break;
	case 3: display_at_beg();
			break;
	case 4: delete_end();
			break;
	case 5: display_op();
			break;
	case 0: exit(0);
			break;
	default:
		;
	}
}

int main(void) {
    while (1) {
        menu();
        choice();
    }
    return EXIT_SUCCESS;
}
