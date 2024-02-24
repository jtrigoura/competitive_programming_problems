//
// Created by jorge on 12/17/2023.
//
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node **adj;
    int numNeighbors;
};

/*int main(){
    int numNodes;
    scanf("%d",numNodes);
    struct Node **nodeList= (struct Node**)malloc(sizeof(struct Node**)*numNodes);
    for(int i=0; i< numNodes; i++){
        char*adjInput;
        scanf("%s",adjInput);
        int adjLength=0;
        for(int i=0; i< strlen(adjInput); i++){
            if(adjInput!=' ')
                adjLength++;
        }
        int
    }
    return 0;
}*/
