#include <stdio.h>
#include <stdlib.h>

void enterArray(int n, int array[n][n]){
    printf("Enter numbers between -1000 and 1000.\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-1000 || array[i][j]>1000){
                printf("You entered a wrong number! Try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printArray(int n, int array[n][n]){
    printf("The array is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int Function1(int n, int array[n][n], int D[n]){
    int index = 0;
    int P;
    printf("Enter number of P: ");
    scanf("%d", &P);

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(i > j && array[i][j]>P){
                D[index++] = array[i][j];
            }
        }
    }
    return index;
}

void printNewArr(int n, int newArr[n]){
    printf("The new arrays is:\n");
    for(int i=0; i<n; i++){
        printf("%d ", newArr[i]);
    }
    printf("\n");
}

void BubbleSort(int n, int newArr[n]){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(newArr[i]>newArr[j]){
                temp = newArr[i];
                newArr[i] = newArr[j];
                newArr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols of matrix(n): ");
    scanf("%d", &n);

    int array[n][n];
    int newArr[n];

    enterArray(n, array);
    printArray(n, array);

    int f1 = Function1(n, array, newArr);
    printNewArr(f1, newArr);

    BubbleSort(f1, newArr);
    printf("After sorting!\n");
    printNewArr(f1,newArr);

    return 0;
}
