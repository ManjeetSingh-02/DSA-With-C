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
        for(j = i+1 ; j < n ; j++) {
            if(a[i] > a[j]) {
                temp = a[i] ;
                a[i] = a[j] ;
                a[j]  = temp ;
            }
        }
    }

    printf("After Sorting :\n") ;
    for(i = 0 ; i < n ; i++) {
        printf("%d\n", a[i]) ;
    }
}