#include <stdio.h>
#include <stblib.h>
#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE]
int top = -1;					

void push(element item) {					//push item into stack
	if (top >= STACK_SIZE - 1) {			//if top+1 is the same as stack size, the stack is full
		printf("\nSTACk is FULL\n");
		return;
	}
	else									//If stack is not full, push item into stack and top should refer the last item
		stack[++top] = item;
}

element pop() {								//pop an item (In stack, the last item should be poped
	if (top == -1) {						//EMPTY
		printf("\n STACK is EMPTY\n");
		return 0;
	}
	else return stack[top--];			
}

void del() {								//delete the last item in stack
	if (top == -1) {
		printf("\n STACK is EMPTY\n");
		return 0;
	}
	else top--;
}

element peek() {							//find the most recently added item. 
	if (top == -1) {
		printf("\n STACK is EMPTY\n");
		return 0;
	}
	else return stack[top];
}

void printStack() {	
	int i;
	printf("\n STACK [");
	for (i = 0; i <= top; i++)				//print all item in stack in order
		printf("%d", stack[i]);
	printf("] \n");
}

void main(void) {
	int item;
	printStack();
	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	item = peak;
	printStack();
	printf("peek top = %d", item);

	del();
	printStack();

	item = pop();
	printStack();
	printf("pop top = %d", item);

	getchar();
}