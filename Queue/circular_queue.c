#include <stdio.h>

int front = -1 , rear = -1 , max , a[100] ;

void enque(int) ;
void deque() ;
void display() ;

void main() {
	int i , n ;
	
	printf("Enter How Many Items You Want To Push In Queue :\n") ;
	scanf("%d", &max) ;
	
	for(i = 1 ; i <= max ; i++) {
		printf("\nEnter %d Item -\n", i) ;
		scanf("%d", &n) ;
		
		enque(n) ;
	}
    display() ;

    deque() ;
    printf("Enter Another Element :\n") ;
    scanf("%d", &n) ;
    enque(n) ;
    display() ;
}

void enque(int x) {
    if ((front == rear + 1) || (front == 0 && rear == max - 1)) {
        printf("\nOverflow") ;
    }
    else {
        if(front == -1) {
            front = 0 ;
        }
    	rear = (rear+1) % max ;
        a[rear] = x ;
        printf("\nEnqued") ;
    }
}

void deque() {
    if(front == -1) {
        printf("\nEmpty") ;
    }
    else {
        if(front == rear) {
            front = -1 ;
            rear = -1 ;
        }
        else {
        front = (front+1) % max ;
        }
        printf("\nDequed") ;
    }
}

void display() {
    int i ;
    for(i = front ; i != rear ; i = (i+1) % max) {
        printf("\n%d", a[i]) ;
    }
    printf("\n%d", a[i]) ;
}