#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void enter_array(int n, int array[n][n]){
    printf("Enter array between -10 and 10.\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
                scanf("%d", &array[i][j]);
                while(array[i][j]<-10 || array[i][j]>10){
                    printf("This number is out of borders. Try again!\n");
                    scanf("%d", &array[i][j]);
            }
        }
    }
}

void print_array(int n, int array[n][n]){
    printf("The matrix is:\n");
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", array[i][j]);
        }
    printf("\n");
    }
}

int new_arrayFunc(int n, int array[n][n], int new_array[n*n]){
    int index=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(pow(array[i][j],2)>50){
                new_array[index++] = array[i][j];
            }
        }
    }
    return index;
}

void print_new_array(int element, int new_array[element]){
    printf("New array is:\n");
    for(int i=0;i<element;i++){
        printf("%d ", new_array[i]);
    }
    printf("\n");
}

void bubble_sort(int element, int new_array[element]){
    int temp;
    for(int i=0;i <element-1;i++){
        for(int j= i+1; j < element;j++){
            if(new_array[i]>new_array[j]){
                temp = new_array[i];
                new_array[i]=new_array[j];
                new_array[j]=temp;
            }
        }
    }
}

int main()
{
    printf("This program prints squares which are grater than 50!\n");
    printf("Margarita Barakova\n");

    int n;
    printf("Enter number of rows and cols of matrix(n): ");
    scanf("%d", &n);

    int array1[n][n];
    enter_array(n, array1);
    print_array(n, array1);

    int new_array[n*n];
    int element = new_arrayFunc(n, array1, new_array);
    print_new_array(element, new_array);

    bubble_sort(element, new_array);
    printf("After sorting is:\n");
    print_new_array(element, new_array);
    return 0;
}
