#include <stdio.h>

void main() {
    int i , y , x , a[10] = {0,0,0,0,0,0,0,0,0,0} ;

    printf("Enter 5 Elements :\n") ;
    for(i = 0; i < 5 ; i++) {
        scanf("%d", &a[i]) ;
    }

    printf("Enter New Element You Want To Be Insert : ") ;
    scanf("%d", &x) ;

    printf("Enter The Position Where You Want To Insert New Element : ") ;
    scanf("%d", &y) ;

    if(y > 10) {
        printf("Position Cannot Be More Than 10") ;
    }
    else {
        y-- ;

        for(i = 10 ; i >= y ; i--) {
            a[i+1] = a[i] ;
        }
        
        a[y] = x ;

        printf("After Insertion :\n") ;
        for(i = 0 ; i < 10 ; i++) {
            printf("%d\n", a[i]) ;
        }
    }
}