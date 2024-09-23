#include <stdio.h>

void main() {
    int i , n , x , high , low , mid , a[100] ;

    printf("Enter Total No OF Elements : ") ;
    scanf("%d", &n) ;

    printf("Enter %d Elements :\n", n) ;
    for(i = 0; i < n ; i++) {
        scanf("%d", &a[i]) ;
    }

    printf("Enter New Element You Want To Search : ") ;
    scanf("%d", &x) ;

    low = 0 ;
    high = n-1 ;
    mid = (low + high) / 2 ;

    while (low <= high)
    {
        if(a[mid] == x) {
            printf("Element Found At %d Position", mid+1) ;
            break ;
        }
        else if(a[mid] < x) {
            low = mid+1 ;
        }
        else {
            high = mid-1 ;
        }
        mid = (low + high) / 2 ;
    }

    if(low > high) {
        printf("Element Is Not In The List") ;
    }
}