#include <stdio.h>

void create(int) ;
void max_heapify(int a[] , int) ;
void display() ;

int a[100] , max = -1 ;

void main() {
    int i , n , x ;

    printf("Enter Total No OF Elements : ") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &x) ;
        create(x) ;
    }

    for(i = (max/2) ; i >= 0 ; i--) {
        max_heapify(a , i) ;
    }

    display() ;
}

void create(int x) {
    max++ ;
    a[max] = x ;
}

void max_heapify(int a[] , int i) {
    int par = i , lc = (2*i)+1 , rc = (2*i)+2  , i_large , t ;

    if(a[lc] > a[par] && lc <= max) {
        i_large = lc ;
    }
    else {
        i_large = par ;
    }

    if(a[i_large] < a[rc] && rc <= max) {
        i_large = rc ;
    }

    if(i_large != i) {
        t = a[i_large] ;
        a[i_large] = a[i] ;
        a[i] = t ;
        max_heapify(a , i_large) ;
    }
}

void display() {
    int i ;
    printf("After Sorting :\n") ;
    for(i = 0 ; i <= max ; i++) {
        printf("Parent - %d , LeftChild - %d , RightChild - %d", a[i] , a[(2*i)+1] , a[(2*i)+2]) ;
        printf("\n") ;
        // printf("%d\n", a[i]) ;
    }
}