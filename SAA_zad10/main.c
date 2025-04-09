#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n][n]){
    printf("Enter numbers between -20 and 20.\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-20 || array[i][j]>20){
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

int SumPositiveInRow(int n, int array[n][n], int new_array[n*n]){
    int index=0;
    for(int i=0; i<n; i++){
        int sumRow = 0;
        for(int j=0; j<n; j++){
            if(array[i][j]>0){sumRow = sumRow + array[i][j];}
            //else {printf("There is only negative numbers! I can't sum it!\n");}
        }
        new_array[index++] = sumRow;
        printf("The sum of row[%d] is %d.\n", i, sumRow);
    }
    return index;
}

void print_new_element(int n, int new_array[n*n]){
    printf("The new array is:\n");
    for(int i=0; i<n; i++){
        printf("%d ", new_array[i]);
    }
    printf("\n");
}

void InsertionSort(int element, int new_array[element]){
    for(int i=1; i<element; i++){
        int key = new_array[i];
        int j=i;
        while((j>0) && (new_array[j-1]> key)){
            new_array[j] = new_array[j-1];
            j--;
        }
        new_array[j] = key;
    }
}

int main()
{
    int n;
    printf("The row and cols of matrix are(n): ");
    scanf("%d", &n);
    while(n < 1 || n > 15){
        printf("You entered a wrong number! Try again!\n");
        scanf("%d", &n);
    }

    int array[n][n];
    enter_array(n, array);
    print_array(n, array);

    int new_array[n*n];

    int element = SumPositiveInRow(n,array, new_array);
    print_new_element(element, new_array);

    InsertionSort(element, new_array);
    printf("After sorting!\n");
    print_new_element(element, new_array);

    return 0;
}
