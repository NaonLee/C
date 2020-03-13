#include <studio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;

void push(element item) {										//linked list push func
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n Stack is empty \n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek() {
	element item;
	if (top == NULL) {
		printf("\n Stack is empty \n");
		return 0;
	}
	else {
		item = top->data;
		return item;
	}
}

void del() {
	stackNode* temp;
	if (top == NULL) {
		printf("\n Stack is empty \n");
	}
	else {
		temp = top;
		top = top->link;
		free(temp);
	}
}

void printStack() {
	stackNode* p = top;
	printf("\n Stack [");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

int testPair(char* exp) {				//Check if there are brackets
	char symbol, open_pari;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(' :
		case '{' :
		case '[' :
			push(symbol); break;
		case ')' :
		case '}' :
		case ']' :
			if (top == NULL) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') || (open_pair == '{' && symbol != '}') ||
					(open_pair == '[' && symbol != ']')) return 0;
				else break;
			}
		}
	}

	if (top == NULL) return 1;
	else return 0;
}

void main(void) {
	char* express = "{(A+B)/C}+3-[E*(D+F)]}";
	printf("*s", express);
	if (testPair(express) == 1) printf("The brackets are in pair");
	else printf("There are some missing brackets!");

	getchar();
}