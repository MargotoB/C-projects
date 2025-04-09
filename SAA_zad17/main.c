#include <stdio.h>
#include <stdlib.h>

void enterArray(int n, int array[n][n]){
    printf("Enter numbers between -500 and 1000.\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-500 || array[i][j]>1000){
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

int MaxInRow(int n, int array[n][n], int row){
    int max = -500;
    array[row][0];
    for(int i=0; i<n; i++){
        if(max<array[row][i]){
            max = array[row][i];
        }
    }
    return max;
}

int MinInCol(int n, int array[n][n], int col){
    int min = 1000;
    array[0][col];
    for(int j=0; j<n; j++){
        if(min>array[j][col]){
            min = array[j][col];
        }
    }
    return min;
}

void newArray(int n, int array[n][n], int newArrayMax[n], int newArrayMin[n]){
    for(int i=0; i<n; i++){
        int max = MaxInRow(n, array, i);
        newArrayMax[i] = max;
        printf("The max element in row[%d] is %d\n", i+1, max);
    }

    for(int j=0; j<n; j++){
        int min = MinInCol(n, array, j);
        newArrayMin[j] = min;
        printf("The min element in col[%d] is %d\n", j+1, min);
    }
}

void printNewArray(int n, int newArr[n]){
    printf("The new array is:\n");
    for(int i=0;i<n;i++){
            printf("%d ", newArr[i]);
    }
        printf("\n");
}

void BubbleSorting(int n, int newArray[n]){
    int temp;
    for(int i=0; i < n-1; i++){
        for(int j = i+1; j<n; j++){
            if(newArray[i]>newArray[j]){
                temp = newArray[i];
                newArray[i] = newArray[j];
                newArray[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols in matrix(n): ");
    scanf("%d", &n);
    int array[n][n];
    int new_arrayA[n];
    int new_arrayB[n];

    enterArray(n, array);
    printArray(n, array);

    newArray(n, array, new_arrayA, new_arrayB);

    printNewArray(n, new_arrayA);
    printNewArray(n, new_arrayB);

    BubbleSorting(n, new_arrayA);
    BubbleSorting(n, new_arrayB);

    printf("After sorting!\n");

    printNewArray(n, new_arrayA);
    printNewArray(n, new_arrayB);

    return 0;
}
