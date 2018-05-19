#include<stdio.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

void main() {
    int node = 0, value, i;

    char c;
    FILE *in_file;
    clrscr();
    in_file = fopen("number.txt", "r");
    if (in_file == NULL) {
        printf("Can't open file for reading.\n");
    } else {

        while (c != EOF) {
            fscanf(in_file, "%d", &value);
            c = fgetc(in_file);
            if (feof(in_file)) {
                break;
            }
            if (value >= 0) {
                push(value);
                node++;
            } else {
                if (node < 5) {
                    printf("ERROR");
                    getch();
                    exit(0);
                } else {
                    for (i = 1; i <= 5; i++) {
                        pop();
                    }
                    node = node - 5;
                }
            }
        }
        display();
    }
}
void push(int value) {
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    getch();
    printf("\nInsertion is Success!!!\n");
}
void pop() {
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else {
        struct Node *temp = top;
        printf(" %d ", temp->data);
        top = temp->next;
        free(temp);
    }
}
void display() {
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else {
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL", temp->data);
    }
}