#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n][n]){
    printf("Enter numbers between 1 and 100.\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<1 || array[i][j]>100){
                printf("You entered a wrong number. Try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void print_array(int n, int array[n][n]){
    printf("The array is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int findElemInMainDiag(int n, int arrayA[n][n], int arrayB[n]){
    int index = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                arrayB[index++] = arrayA[i][j];
            }
        }
    }
    return index;
}

void CountingSort(int elem, int arrayB[elem]){
    int max = 100;
    int count[max+1];
    int output[elem];

    for(int i=0; i<= max; i++){
        count[i] += count[i - 1];
    }

    for(int i=0; i< elem; i++){
        count[arrayB[i]]++;
    }

    for(int i=0; i<= max; i++){
        count[i] += count[i-1];
    }

    for(int i = elem - 1;i>=0; i++){
        output[count[arrayB[i]-1]] = arrayB[i];
        count[arrayB[i]]--;
    }

    for(int i=0; i < elem; i++){
        arrayB[i] = output[i];
    }
}

int main()
{
    int n = 6;
    int arrayA[n][n];
    int arrayB[n];

    enter_array(n, arrayA);
    print_array(n, arrayA);
    int element = findElemInMainDiag(n, arrayA, arrayB);

    CountingSort(element, arrayB);
    printf("The fourth biggest element in main diagonal is: %d", arrayB[3]);

    return 0;
}
