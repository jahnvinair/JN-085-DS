#include <stdio.h>
#define V 4

void init(int arr[][V]){
    int i,j;
    for (i=0;i<V;i++){
        for (j=0;j<V;j++){
            arr[i][j]=0;
        }
    }
}

void addEdge(int arr[][V],int i, int j){
    arr[i][j]=1;
    arr[j][i]=1;
}

void printAdjMatrix(int arr[][V]){
    int i,j;
    for (i=0;i<V;i++){
        printf("%d",i);
        for (j=0;j<V;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int adjMatrix[V][V];

    init(adjMatrix);
    printAdjMatrix(adjMatrix);
    printf("\n");
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,3,4);
    addEdge(adjMatrix,5,6);
    addEdge(adjMatrix,7,8);
}
