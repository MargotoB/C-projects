#include <stdio.h>
#include <stdlib.h>

void enter_array(int rows, int cols, int array[rows][cols]){
    printf("Enter the numbers between -1000 and 1000.\n");
    for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-1000 || array[i][j]>1000){
                printf("You entered a wrong number!Try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void print_array(int rows, int cols, int  array[rows][cols]){
    printf("The array is:\n");
    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void new_array_Function(int rows, int cols, int array[rows][cols]){
    int M;
    printf("Enter a lower negative border M: ");
    scanf("%d", &M);
    while(M>0){
        printf("You entered a positive number! Try again\n");
        scanf("%d", &M);
    }

    int N;
    printf("Enter a upper border N: ");
    scanf("%d", &N);

    int Q;
    printf("Enter a number Q: ");
    scanf("%d", &Q);

    int count =0;
    for(int i=0; i < rows; i++){
        for(int j=0; j<cols; j++){
            if(array[i][j] > M && array[i][j] < N && array[i][j]<0){
                array[i][j] = Q;
                count++;
            }
        }
    }
    printf("The count is: %d\n", count);
}


int main()
{
    printf("This program is finding negative numbers and switches them with Q!\n ");
    printf("Margoto\n");

    int rows = 2;
    int cols = 4;
    int array1[rows][cols];

    enter_array(rows,cols, array1);
    print_array(rows, cols, array1);

    new_array_Function(rows, cols, array1);
    print_array(rows, cols, array1);
    return 0;
}
