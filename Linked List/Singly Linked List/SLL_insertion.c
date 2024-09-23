#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *next ;
} ;

struct node *head = NULL ;
int max = 0 ;

void create(int) ;
void insertatsp(int , int) ;
void display() ;

void main() {
    int i , x , y , n ;

    printf("Enter Total No OF Elements :\n") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &x) ;
        create(x) ;
    }

    printf("Linked List Created :\n") ;
    display() ;

    printf("Enter Element You Want To Insert :\n") ;
    scanf("%d", &x) ;

    printf("Enter Position Of The Element You Want To Insert :\n") ;
    scanf("%d", &y) ;

    if(y > (max+1)) {
        printf("Position Must Be Less Or Equal To %d", max+1) ;
        exit(1) ;
    }
    else {
        insertatsp(x , y) ;
    }

    printf("After Insertion , List Is :\n") ;
    display() ;
}

void create(int x) {
    struct node *temp ;

    temp = (struct node *) malloc(sizeof(struct node)) ;
    temp->data = x ;
    temp->next = NULL ;

    if(head == NULL) {
        head = temp ;
        max++ ;
    }
    else {
        struct node *p ;
        p = head ;
        while(p->next != NULL) {
            p = p->next ;
        }
        p->next = temp ;
        max++ ;
    }
}

void insertatsp(int x , int y) {
    struct node *temp ;
    int i = 1 ;

    temp = (struct node *) malloc(sizeof(struct node)) ;
    temp->data = x ;
    temp->next = NULL ;

    if(y == 1) {
        temp->next = head ;
        head = temp ;
        max++ ;
    }
    else {
        struct node *p ;
        p = head ;

        while(i < (y-1)) {
            p = p->next ;
            i++ ;
        }
        temp->next = p->next ;
        p->next = temp ;
        max++ ;
    }
}

void display() {
    struct node *p ;
    p = head ;
    printf("Total Elements Are : %d", max) ;
    while(p != NULL) {
        printf("\n%d", p->data) ;
        p = p->next ;
    }
}