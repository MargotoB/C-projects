#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n][n]){
    printf("Enter numbers:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &array[i][j]);
        }
    }
}

void print_array(int n, int array[n][n]){
    printf("The array is:\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int sumOfRows(int n, int array[n][n], int new_array[n*n]){
    int index=0;
    for(int i=0; i<n; i++){
        int sumRow=0;
            for(int j=0; j<n; j++){
                sumRow = sumRow+array[i][j];
            }
                new_array[index++] = sumRow;
                printf("The sum of row[%d] is: %d\n", i, sumRow);
    }
    return index;
}

void insertionSort(int element, int new_array[element]){
    for(int i=1; i<element; i++){
        int key = new_array[i];
        int j = i;
        while((j>0) && (new_array[j-1]>key)){
            new_array[j]= new_array[j-1];
            j--;
        }
        new_array[j] = key;
    }
}

void printNewArray(int element, int new_array[element]){
    printf("The new array is:\n");
    for(int i=0; i<element; i++){
        printf("%d ", new_array[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the rows and cols of array(n): ");
    scanf("%d", &n);

    int array[n][n];
    enter_array(n, array);
    print_array(n, array);

    int new_array[n*n];
    int element = sumOfRows(n,array, new_array);

    insertionSort(element, new_array);
    printf("After sorting!\n");
    printNewArray(element, new_array);
    return 0;
}
