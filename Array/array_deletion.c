#include <stdio.h>

void main() {
    int i , x , a[10] = {0,0,0,0,0,0,0,0,0,0} ;

    printf("Enter 5 Elements :\n") ;
    for(i = 0; i < 5 ; i++) {
        scanf("%d", &a[i]) ;
    }

    printf("Enter The Position Where You Want To Delete Element : ") ;
    scanf("%d", &x) ;

    if(x > 10) {
        printf("Position Cannot Be More Than 10") ;
    }
    else {
        x-- ;

        for(i = x ; i < 10 ; i++) {
            a[i] = a[i+1] ;
        }

        printf("After Deletion :\n") ;
        for(i = 0 ; i < 10 ; i++) {
            printf("%d\n", a[i]) ;
        }
    }
}