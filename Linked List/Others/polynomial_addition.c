#include <stdio.h>
#include <stdlib.h>

struct  node {
	int coeff ;
	int pow ;
	struct node *next ;
};

struct node *polym = NULL ;
struct node *poly1 = NULL ;
struct node *poly2 = NULL ;

void enterpoly(int , int , int) ;
void addtwopoly() ;
void result(int , int) ;
void display() ;

void main() {
	int i , a , b , tp1 , tp2 ;
	
	printf("Enter The No Of Terms In Polynomial-1 :\n") ;
	scanf("%d", &tp1) ;
	
	if(tp1 == 0) {
		printf("\nTerms Should Be More Than 0") ;
		exit(1) ;
	}
	else {
		for(i = 0 ; i < tp1 ; i++) {
			printf("\nEnter Polynomial-1 -> Term - %d -> Coefficient :\n", i+1) ;
			scanf("%d", &a) ;
			printf("Enter Polynomial-1 -> Term - %d -> Power :\n", i+1) ;
			scanf("%d", &b) ;
			
			enterpoly(a , b , 1) ;
		}
	}
	
	printf("\nEnter The No Of Terms In Polynomial-2 :\n") ;
	scanf("%d", &tp2) ;
	
	if(tp2 == 0) {
		printf("\nTerms Should Be More Than 0") ;
		exit(1) ;
	}
	else {
		for(i = 0 ; i < tp2 ; i++) {
			printf("\nEnter Polynomial-2 -> Term - %d -> Coefficient :\n", i+1) ;
			scanf("%d", &a) ;
			printf("Enter Polynomial-2 -> Term - %d -> Power :\n", i+1) ;
			scanf("%d", &b) ;
			
			enterpoly(a , b , 2) ;
		}
	}
	addtwopoly() ;
	display() ;
}

void enterpoly(int x , int y , int z) {
	struct node *temp ;
	
	temp = (struct node *) malloc(sizeof(struct node)) ;
	
	if(temp == NULL) {
		printf("\nMemory Not Allocated , Try Again") ;
		exit(1) ;
	}
	else {
		temp->coeff = x ;
		temp->pow = y ;
		temp->next = NULL ;
	}
	
	if(z == 1) {
		if(poly1 == NULL) {
			poly1 = temp ;
		}
		else {
			struct node *p ;
			p = poly1 ;
		
			while(p->next != NULL) {
				p = p->next ;
			}
			p->next = temp ;
		}
	}
	else {
		if(poly2 == NULL) {
			poly2 = temp ;
		}
		else {
			struct node *p ;
			p = poly2 ;
		
			while(p->next != NULL) {
				p = p->next ;
			}
			p->next = temp ;
		}
	}
}

void addtwopoly() {
	struct node *temp , *p , *q ;
	
	temp = (struct node *) malloc(sizeof(struct node)) ;
	
	if(temp == NULL) {
		printf("\nMemory Not Allocated , Try Again") ;
		exit(1) ;
	}
	else {
		temp->coeff = 0 ;
		temp->pow = 0 ;
		temp->next = NULL ;
	}
	
	p = poly1 ;
	q = poly2 ;
	
	while(p != NULL && q != NULL) {
		if(p->pow == q->pow) {
			temp->coeff = p->coeff + q->coeff ;
			temp->pow = p->pow ;
			p = p->next ;
			q = q->next ;
		}
		else if(p->pow >= q->pow) {
			temp->coeff = p->coeff ;
			temp->pow = p->pow ;
			p = p->next ;
		}
		else {
			temp->coeff = q->coeff ;
			temp->pow = q->pow ;
			q = q->next ;
		}
		
		result(temp->coeff , temp->pow) ;
	}
	
	if(p == NULL) {
		while(q != NULL) {
			result(q->coeff ,  q->pow) ;
			q = q->next ;
		}
	}
	else {
		while(p != NULL) {
			result(p->coeff ,  p->pow) ;
			p = p->next ;	
		}
	}
}

void result(int x , int y) {
	struct node *temp ;
	
	temp = (struct node *) malloc(sizeof(struct node)) ;
	
	if(temp == NULL) {
		printf("\nMemory Not Allocated , Try Again") ;
		exit(1) ;
	}
	else {
		temp->coeff = x ;
		temp->pow = y ;
		temp->next = NULL ;
	}
	
	if(polym == NULL) {
		polym = temp ;
	}
	else {
		struct node *z ;
		z = polym ;
		
		while(z->next != NULL) {
			z = z->next ;
		}
		z->next = temp ;
	}
}

void display() {
	struct node *p ;
	p = polym ;
	while(p != NULL) {
		if(p->pow == 0) {
			printf("+(%d)", p->coeff) ;
		}
		else if(p->pow == 1) {
			printf("+(%dx)", p->coeff) ;
		}
		else {
			printf("+(%dx^%d)", p->coeff , p->pow) ;
		}
		p = p->next ;
	}
}