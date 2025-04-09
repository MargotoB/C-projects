#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n][n]){
    printf("Enter numbers between -999 and 999.\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-999 || array[i][j]>999){
                printf("The number is out of borders. Try again!\n");
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

void Function1(int n, int array[n][n], int A, int B, int R){
    int count=0;
    float sum=0.0;
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            if(i<j){
                if(array[i][j] % R == 0 && array[i][j]>A && array[i][j]<B){
                    sum += array[i][j];
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
    float average = sum/count;
    printf("The average is: %.2f", average);
}

int main()
{
    printf("This program finds average and are in specific interval!\n");
    printf("Margarita Barakova\n");

    int n;
    printf("Enter the number of rows and cols of matrix(n): ");
    scanf("%d", &n);

    int array[n][n];
    enter_array(n, array);
    print_array(n, array);

    int A,B,R;
    printf("Enter lower border: ");
    scanf("%d", &A);
    printf("Enter upper border: ");
    scanf("%d", &B);
    printf("Enter multiple: ");
    scanf("%d", &R);

    Function1(n, array, A, B, R);
    return 0;
}
