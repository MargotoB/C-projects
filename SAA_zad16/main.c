#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void final_comon_elements(int A[], int m, int B[], int n,int C[], int p, int D[], int *size){
    bool inA[101] = {false}, inB[101] = {false}, inC[101] = {false};
    int i,j=0;

    for(i=0; i<m; i++){
        if(A[i]>=1 && A[i]<=100){
            inA[A[i]] = true;
        }
    }

    for(i=0; i<n; i++){
        if(B[i]>=1 && B[i]<=100){
            inB[B[i]] = true;
        }
    }

    for(i=0; i<p; i++){
        if(C[i]>=1 && C[i]<=100){
            inC[C[i]] = true;
        }
    }

    for(i = 1; i<=100; i++){
        if(inA[i] && inB[i] && inC[i]){
            D[j++] = i;
        }
    }
    *size = j;
}

int main()
{
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int C[] = {4,5,6,7};
    int D[100];
    int size,i;

    final_comon_elements(A,4, B, 4, C,4, D, &size);

    printf("Same element in arrays is: ");
    for(int i=0; i<size; i++){
        printf("%d ", D[i]);
    }
    printf("\n");

    return 0;
}
