#include <stdio.h>
#include <stdlib.h>

int top = -1 , max , a[100] ;

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
	if(top >= max-1) {
		printf("\nOverflow") ;
	}
	else {
		top++ ;
		a[top] = x ;
		printf("\nPushed\n") ;
	}
}

void pop() {
	if(top == -1) {
		printf("\nUnderflow") ;
	}
	else {
		top-- ;
		printf("\nPoped\n") ;
	}
}

void display() {
	int i ;
	
	for(i = 0 ; i <= top ; i++) {
		printf("\n%d", a[i]) ;
	}
}