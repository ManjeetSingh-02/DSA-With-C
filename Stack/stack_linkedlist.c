#include <stdio.h>
#include <stdlib.h>

struct node {
	int data ;
	struct node *next ;
};

struct node *head = NULL ;
int top = 0 , max ;

void push(int x) ;
void pop() ;
void display() ;

void main() {
	int i , n ;
	
	printf("Enter How Many Items You Want To Push In Stack :\n") ;
	scanf("%d", &max) ;
	
	for(i = 1 ; i <= max ; i++) {
		printf("\nEnter %d Item -\n", i) ;
		scanf("%d", &n) ;
		
		push(n) ;
	}
	
	display() ;
	
	for(i = 1 ; i <= max ; i++) {
		pop() ;
	}
}

void push(int x) {
	if(top > max) {
		printf("\nOverflow") ;
	}
	else {
		struct node *temp ;
		
		temp = (struct node *) malloc(sizeof(struct node)) ;
		temp->data = x ;
		temp->next = NULL ;
		
		if(head == NULL) 
		{
			top++ ;
			head = temp ;
			printf("\nPushed") ;
		}
		else {
			top++ ;
			temp->next = head ;
			head = temp ;
			printf("\nPushed") ;
		}
	}
}

void pop() {
	
	if(head == NULL) {
		printf("\nUnderflow") ;
	}
	else {
		struct node *p ;
		
		p = head ;
		top-- ;
		
		head = head->next ;
		p->next = NULL ;
		free(p) ;
		printf("\nPoped") ;
	}
}

void display() {
	struct node *p ;
	p = head ;
	
	while(p != NULL) {
		printf("\n%d", p->data) ;
		p = p->next ;
	}
}