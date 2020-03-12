#include <studio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {						//declare list node structure
	char data[10];
	struct ListNode* link;
}listNode;

typedef struct {						
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h*);
void addLastNode(linkedList_h*, char*);
void reverse(linkedList_h*);
void deleteLastNode(linkedList_h*);
void printList(linkedlist_h*);

linkedList_h* createLinkedList_h(void) {		//create node head
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head;
	return L;
}

void addLastNode(linkedList_h* L, char* x) {		//add a new node to the last
	listNode* newNode;
	listNode* p;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);						//put parameter into data field
	newNode->link = NULL;							//Since the new node is the last node, link should be null

	if (L->head == NULL) {							//if the list is empty
		L->head = newNode;							//head pointer will point new node
		return;
	}
	else {
		p = L->head;
		while (p->link != NULL) p = p->link;		//search the last node
		p->link = newNode;
	}
}

void reverse(linkedList_h* L) {						//reverse the list
	listNode* p = L->head;
	listNode* q = NULL;
	listNode* r = NULL;

	while (p != NULL) {						
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

void deleteLastNode(linkedList_h* L) {
	listNode* previous;
	listNode* current;
	if (L->head == NULL) return;					//list is empty
	if (L->head->link == NULL) {					//list has only one node
		free(L->head);
		L->head = NULL;
		return;
	}
	else {
		previous = L->head;	
		current = L->head->link;
		while (current->link != NULL) {
			previous = current;
			current = previous->link;
		}
		free(current);
		previous->link = NULL;
	}
}

void freeLinkedList_h(linkedList_h* L) {				//release all nodes in the lst
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {							//print out the data from first to last
		printf("$s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf("\n");
}

int main() {
	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1) create an empty list \n");
	printList(L); getchar();

	printf("(2) add three nodes to the list"\n);
	addLastNode(L, 'Mon');
	addLastNode(L, 'Tue');
	addLastNode(L, 'Wed');
	printList(L); getchar();

	printf("(3) delete the last node \n");
	deleteLastNode(L);
	printList(L); getchar();

	printf("(4) reverse an order of the list \n");
	reverse(L);
	printList(L); getchar();

	printf("(5) make the list to be empty \n");
	freeLinkedList_h(L);
	printList(L); getchar();

	return 0;
}