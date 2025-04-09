#include <stdio.h>
#include <stdlib.h>

void enter_arrays(int n, int array[n][n]){
    printf("Insert numbers between -1000 and 1000.\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-1000 || array[i][j]>1000){
                printf("The number is out of borders! Try again!\n");
                scanf("%d ", &array[i][j]);
            }
        }
    }
}

void print_array(int n, int array[n][n]){
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void find_and_sum_diagonals(int n, int matrix1[n][n], int matrix2[n][n], int new_matrix[n])
{
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                new_matrix[i] = matrix1[i][i]+matrix2[i][i];
            }
        }
    }
}

void print_new_matrix(int n, int new_matrix[n]){
    printf("The array is: ");
    for(int i=0; i<n ; i++){
        printf("%d ", new_matrix[i]);
    }
    printf("\n");
}

void bubble_sorting(int n, int array[n]){
    int temp;

    for(int i=0; i < n - 1; i++){
        for(int j= i+1; j<n; j++){
            if(array[i]>array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    printf("This program combines and sorts two arrays!\n");
    printf("Margarita Barakova\n");

    int n;
    printf("Enter number of rows and cols of matrix(n): ");
    scanf("%d", &n);

    int array1[n][n];
    enter_arrays(n, array1);
    print_array(n, array1);

    int array2[n][n];
    enter_arrays(n, array2);
    print_array(n, array2);

    int new_array[n];
    find_and_sum_diagonals(n, array1, array2, new_array);
    print_new_matrix(n, new_array);

    bubble_sorting(n, new_array);
    printf("The array after sorting is:\n");
    print_new_matrix(n, new_array);

    return 0;
}
