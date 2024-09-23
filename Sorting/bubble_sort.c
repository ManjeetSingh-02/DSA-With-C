#include <stdio.h>

void main() {
    int i , n , j , temp , a[100] ;

    printf("Enter Total No OF Elements : ") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &a[i]) ;
    }

    for(i = 0 ; i < n-1 ; i++) {
        for(j = 0 ; j < n-1-i ; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j] ;
                a[j] = a[j+1] ;
                a[j+1]  = temp ;
            }
        }
    }

    printf("After Sorting :\n") ;
    for(i = 0 ; i < n ; i++) {
        printf("%d\n", a[i]) ;
    }
}