#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct booktype{
	int num;
	char bookName[20];
	char author[15];
	char price[10];
	struct booktype *next;
} BOOK;

int main(void){

	BOOK *head=NULL;
	BOOK *tail=NULL;
	BOOK *p, *del;
	int selector = 0;
	char name[];

	while(1){
		printf("1.add		\n");
		printf("2.delete	\n");
		printf("3.list		\n");
		printf("4.search		\n");
		printf("5.quit		\n");
		scanf("%d",&selector);
		fflush(stdin);

		switch(selector){

		case 1 :
			
			p = (BOOK *)malloc(sizeof(BOOK));						//Create a new node to add book's information
			printf("bookname:");
			scanf("%s", p->bookName);
			printf("Author:");
			scanf("%s",p->author);
			printf("Price:");
			scanf("%s",p->price);
			
			
			p->next = NULL;										//The inserted book's information will be added to end of the list

			if(head==NULL){										//If book list is empty
				p->num = 1;
				head = p;
			}
			else{
				int temp = 2;
				tail = head;
				while(tail->next != NULL){						//Find the end(tail) of the list
					tail = tail->next;
					temp++;
				}
				p->num = temp;
				tail->next = p;
			}
			break;

		case 2:

			printf("Put the book's name:");						//Get the book's name to delete
			scanf("%s",&name);
			fflush(stdin);
			p = head;											//Start searching the book's name from the start(head)

			if(name==head->bookName){							
				head=p->next;
				break;
			}
			else{
				while(p){
					if((p->next)->bookName==name){				//If the book's names are matched, proceed 'delete'
						del = p->next;
						p->next = del->next;
						break;
					}
					else
						p = p->next;
				}
				break;
			}

		case 3 :

			p = head;												//Print out the Book List
			while(p){
				printf("\nBookName: %s", p->bookName);
				printf("Author : %s\n",p->author);
				printf("Price : %s\n", p->price);
				printf("Number : %d\n\n",p->snum);
				p = p->next;
			}
			break;
		
		case 4 :

			printf("Put the book's name:");						//Get the book's name to search
			scanf("%s", &name);
			fflush(stdin);
			p = head;

			else {
				while (p) {
					if (p->bookName == name) {
						printf("Here's book information");
						printf("\nBookName: %s", p->bookName);
						printf("Author : %s\n", p->author);
						printf("Price : %s\n", p->price);
						printf("Number : %d\n\n", p->snum);
						break;
					}
					else{
						p = p->next;
					}
				}
			}

		case 5 :

			return 0 ;

		
		}
	}
	return 0;
}