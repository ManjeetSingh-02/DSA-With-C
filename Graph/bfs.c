#include <stdio.h>

int visited[7] = {0} , eq[100] , front = 0 , rear = 0 ;

void enque(int) ;
void deque() ;

void main() {
    int i , current , N = 6 , graph[6][6] = {{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,1,1,0},{0,0,1,0,0,0},{0,0,1,0,0,1},{0,0,0,0,1,0}};

    enque(1) ;
    visited[0] = 1 ;
    while(front != rear) {
        current = eq[front] ;
        printf("%d\n", current) ;
        deque() ;

        for(i = 0 ; i < 6 ; i++) {
            if(graph[current-1][i] == 1 && visited[i] == 0) {
                visited[i] = 1 ;
                enque(i+1) ;
            }
        }
    }
}

void enque(int x) {
    eq[rear] = x ;
    rear++ ;
}

void deque() {
    eq[front] = 0 ;
    front++ ;
}