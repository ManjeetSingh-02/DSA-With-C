#include <stdio.h>

void main() {
    int i , n , j , key , a[100] ;

    printf("Enter Total No OF Elements : ") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &a[i]) ;
    }

    for(i = 1 ; i < n ; i++) {
        key = a[i] ;
        j = n-1 ;
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j] ;
            j-- ;
        }
        a[j+1] = key ;
    }

    printf("After Sorting :\n") ;
    for(i = 0 ; i < n ; i++) {
        printf("%d\n", a[i]) ;
    }
}