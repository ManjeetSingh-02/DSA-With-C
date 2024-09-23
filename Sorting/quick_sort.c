#include <stdio.h>

void quicksort(int a[] , int , int) ;

void main() {
    int i , n , a[100] ;

    printf("Enter Total No OF Elements : ") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &a[i]) ;
    }

    quicksort(a , 0 , n-1) ;

    printf("After Sorting :\n") ;
    for(i = 0 ; i < n ; i++) {
        printf("%d\n", a[i]) ;
    }
}

void quicksort(int a[] , int first , int last) {
    int i , j , k , pivot ;

    if(first < last) {
        pivot = first ;
        i = first ;
        j = last ;

        while(i < j) {
            while(a[i] <= a[pivot] && i < last) {
                i++ ;
            }
            while(a[j] > a[pivot]) {
                j-- ;
            }
            if(i < j) {
                k = a[i] ;
                a[i] = a[j] ;
                a[j] = k ;
            }
        }
        k = a[pivot] ;
        a[pivot] = a[j] ;
        a[j] = k ;

        quicksort(a , first , j-1) ;
        quicksort(a , j+1 , last) ;
    }
}