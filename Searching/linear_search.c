#include <stdio.h>

void main() {
    int i , x , a[5] ;

    printf("Enter 5 Elements :\n") ;
    for(i = 0; i < 5 ; i++) {
        scanf("%d", &a[i]) ;
    }

    printf("Enter New Element You Want To Search : ") ;
    scanf("%d", &x) ;

    for(i = 0 ; i < 5 ; i++) {
        if(a[i] == x) {
            printf("Element Found At %d Position", i+1) ;
            break ;
        }
    }

    if(i == 5) {
        printf("Element Is Not In The List") ;
    }
}