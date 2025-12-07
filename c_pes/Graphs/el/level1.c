//
// Created by Kishi Kishore N on 07/12/25.
//
#include <stdio.h>

int main(){
    int v,e;

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    printf("Enter number of edge: ");
    scanf("%d",&e);

    int arr[v][v];

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        for(int j=0; j<sizeof(arr[0])/sizeof(arr[0][0]); j++){
            arr[i][j]= 0;
        }
    }

    printf("\n Edges:\n");
    for(int i=0; i<e; i++){
        int from,to;
        scanf("%d %d",&from, &to);

        arr[from][to] = 1;
        arr[to][from] = 1;
    }

    printf("\n Adjacency Matrix: \n");
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        for(int j=0; j<sizeof(arr[0])/sizeof(arr[0][0]); j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}