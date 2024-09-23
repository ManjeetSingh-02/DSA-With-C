#include <stdio.h>
#include <stdlib.h>

struct node {
	int data ;
	struct node *next ;
};

struct node *head = NULL ;
int front = 0 , rear = 0 , max ;

void enque(int x) ;
void deque() ;
void display() ;

void main() {
	int i , n ;
	
	printf("Enter How Many Items You Want To Push In Stack :\n") ;
	scanf("%d", &max) ;
	
	for(i = 1 ; i <= max ; i++) {
		printf("\nEnter %d Item -\n", i) ;
		scanf("%d", &n) ;
		
		enque(n) ;
	}
	
	display() ;
	
	for(i = 1 ; i <= max ; i++) {
		deque() ;
	}
}

void enque(int x) {
	if(rear > max-1) {
		printf("\nOverflow") ;
	}
	else {
		struct node *temp ;
		
		temp = (struct node *) malloc(sizeof(struct node)) ;
		temp->data = x ;
		temp->next = NULL ;
		
		if(head == NULL) {
			front = 1 ;
			rear = 1 ;
			head = temp ;
			printf("\nEnqued") ;
		}
		else {
			struct node *p ;
			
			p = head ;
			rear++ ;
			
			while(p->next != NULL) {
				p = p->next ;
			}
			p->next = temp ;
			printf("\nEnqued") ;
		}
	}
}

void deque() {
	if(head == NULL) {
		printf("\nUnderflow") ;
	}
	else {
		struct node *p ;
		
		p = head ;
		front++ ;
		
		head = head->next ;
		p->next = NULL ;
		free(p) ;
		printf("\nDequed") ;
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