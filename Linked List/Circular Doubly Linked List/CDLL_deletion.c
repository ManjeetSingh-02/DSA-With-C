#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *left ;
    struct node *right ;
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

    printf("Enter Position Of The Element You Want To Insert :\n") ;
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
    temp->left = NULL ;
    temp->right = NULL ;

    if(head == NULL) {
        temp->left = temp ;
        temp->right = temp ;
        head = temp ;
        max++ ;
    }
    else {
        struct node *p ;
        p = head ;
        while(p->right != head) {
            p = p->right ;
        }
        temp->left = p ;
        p->right = temp ;
        temp->right = head ;
        head->left = temp ;
        max++ ;
    }
}

void deleteatsp(int x) {
    int i = 1 ;

    if(x == 1) {
        struct node *p , *q ;
        p = head ;
        q = head ;
        while(p->right != head) {
            p = p->right ;
        }
        p->right = head->right ;
        head = head->right ;
        q->left = NULL ;
        q->right = NULL ;
        free(q) ;
        max-- ;
    }
    else {
        struct node *p , *q ;
        p = head ;

        while(i < x) {
            q = p ;
            p = p->right ;
            i++ ;
        }
        q->right = p->right ;
        if(x != max) {
            q = q->right ;
            q->left = p->left ;
        }
        else {
            head->left = q ;
        }
        p->left = NULL ;
        p->right = NULL ;
        free(p) ;
        max-- ;
    }
}

void display() {
    struct node *p ;
    p = head ;
    printf("Total Elements Are : %d", max) ;
    while(p->right != head) {
        printf("\n%d", p->data) ;
        p = p->right ;
    }
    printf("\n%d", p->data) ;
}