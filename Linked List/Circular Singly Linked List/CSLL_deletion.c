#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *next ;
} ;

struct node *head = NULL ;
int max = 0 ;

void create(int) ;
void deleteatsp(int) ;
void display() ;

void main() {
    int i , x , n ;

    printf("Enter Total No OF Elements :\n") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &x) ;
        create(x) ;
    }

    printf("Linked List Created :\n") ;
    display() ;

    printf("Enter Position Of The Element You Want To Delete :\n") ;
    scanf("%d", &x) ;

    if(x > max) {
        printf("Position Must Be Less Or Equal To %d", max) ;
        exit(1) ;
    }
    else {
        deleteatsp(x) ;
    }

    printf("After Deletion , List Is :\n") ;
    display() ;
}

void create(int x) {
    struct node *temp ;

    temp = (struct node *) malloc(sizeof(struct node)) ;
    temp->data = x ;
    temp->next = NULL ;

    if(head == NULL) {
        temp->next = temp ;
        head = temp ;
        max++ ;
    }
    else {
        struct node *p ;
        p = head ;
        while(p->next != head) {
            p = p->next ;
        }
        temp->next = head ;
        p->next = temp ;
        max++ ;
    }
}

void deleteatsp(int x) {
    int i = 1 ;

    if(x == 1) {
        struct node *p , *q ;
        p = head ;
        q = head ;
        while(p->next != head) {
            p = p->next ;
        }
        p->next = head->next ;
        head = head->next ;
        q->next = NULL ;
        free(q) ;
        max-- ;
    }
    else {
        struct node *p, *q ;
        p = head ;

        while(i < x) {
            q = p ;
            p = p->next ;
            i++ ;
        }
        q->next = p->next ;
        p->next = NULL ;
        free(p) ;
        max-- ;
    }
}

void display() {
    struct node *p ;
    p = head ;
    printf("Total Elements Are : %d", max) ;
    while(p->next != head) {
        printf("\n%d", p->data) ;
        p = p->next ;
    }
    printf("\n%d", p->data) ;
}