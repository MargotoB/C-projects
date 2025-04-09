#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
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

int find_min(int n, int array[n][n], int rows){
        int min = array[rows][0];
        for(int j=0; j<n; j++){
            if(min>array[rows][j]){
                min = array[rows][j];
        }
    }
    return min;
}

int sum_main_diagonal(int n, int array[n][n]){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                sum += array[i][j];
            }
        }
    }
    return sum;
}

int negative_second_diag(int n, int array[n][n]){
    int count =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i + j == n - 1){
                if(array[i][j]<0){
                    count++;
                }
            }
        }
    }
    return count;
}

int new_Function(int n, int arrayA[n][n], int arrayB[n*n]){
    int index = 0;

    for(int i=0; i<n; i++){
        arrayB[index++] = find_min(n, arrayA, i);
    }
    arrayB[index++] = sum_main_diagonal(n, arrayA);
    arrayB[index++] = negative_second_diag(n, arrayA);

    return index;
}

void Bubble_Sort(int element, int new_array[element]){
    int temp;
    for(int i=0; i<element-1; i++){
        for(int j=i+1; j<element; j++){
            if(new_array[i] > new_array[j]){
                temp = new_array[i];
                new_array[i] = new_array[j];
                new_array[j] = temp;
            }
        }
    }
}

void print_new_array(int element, int new_array[element]){
    printf("The array is:\n");
    for(int i=0; i<element; i++){
            printf("%d ", new_array[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of rows and cols in array(n): ");
    scanf("%d", &n);

    int arrayA[n][n];
    enter_array(n, arrayA);
    print_array(n, arrayA);

    int arrayB[n*n];

    int min;
    for(int i=0; i<n; i++){
        min = find_min(n, arrayA, i);
    }
    int sum = sum_main_diagonal(n,arrayA);
    int neg = negative_second_diag(n, arrayA);

    int element = new_Function(n, arrayA, arrayB);
    print_new_array(element, arrayB);

    Bubble_Sort(element, arrayB);
    printf("After sorting!\n");
    print_new_array(element, arrayB);
    return 0;
}
