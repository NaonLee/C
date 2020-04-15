#include<stdio.h>
#include<stdlib.h>
#define Q_SIZE 100

typedef char element;			
typedef struct {
	element queue[Q_SIZE];				//declare queue
	int front, rear;	
}QueueType;

QueueType* createQueue() {				//create an empty queue
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));			//allocate memory
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType* Q) {				//check the queue if it's empty
	if (Q->front == Q->rear) {
		printf("\n Queue is empty \n");
		return 1;
	}
	else return 0;
}

int isFull(QueueType* Q) {				//check the queue if it's full
	if (Q->rear == Q_SIZE - 1) {
		printf("\n Queue is full \n");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType* Q, element item) {		//insert item to Queue
	if (isFull(Q)) exit(1);						//if Queue is full, exit
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element deQueue(QueueType* Q) {					//return item from Queue and delete it
	if (isEmpty(Q)) exit(1);					//if Queue is empty, there is no item ot return
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

void del(QueueType* Q) {						//delete item form Queue
	if (isEmpty(Q)) exit(1);
	else Q->front++;
}

element peek(QueueType* Q) {					//return the first item in Queue
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1];
}

void printQ(QueueType* Q) {						//print Queue
	int i;
	printf("Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++) {
		printf("%3c", Q->queue[i]);
	}
	printf("]\n");
}

void main(void) {
	QueueType* Q1 = createQueue();
	element data;
	printf("insert A");
	enQueue(Q1, 'A');
	printQ(Q1);

	printf("insert B");
	enQueue(Q1, 'B');
	printQ(Q1);

	printf("delete");
	deQueue(Q1);
	printQ(Q1);

	printf("insert C");
	enQueue(Q1, 'C');
	printQ(Q1);

	data = peek(Q1);
	printf("peek item: %c \n", data);

	printf("delete");
	deQueue(Q1);
	printQ(Q1);
}
