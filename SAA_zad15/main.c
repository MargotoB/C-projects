#include <stdio.h>
#include <stdlib.h>

void enterArray(int n, int array[n][n]){
    printf("Enter elements:\n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d", &array[i][j]);
        }
    }
}

void printArray(int n, int array[n][n]){
    printf("The array is:\n");
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void Function(int n, int array[n][n])
{
    int SP=0, SO=0, SD1=0, SD2 = 0;
    int SN = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(array[i][j]>0){
                SP += array[i][j];
            }
            else if(array[i][j] < 0){
                SO += array[i][j];
            }
            else{
                SN++;
            }

            if(i == j){
                SD1 += array[i][j];
            }
            if(i + j == n - 1){
                SD2 += array[i][j];
            }
        }
    }
    printf("The sum of positive numbers is: %d\n", SP);
    printf("The sum of negative numbers is: %d\n", SO);
    printf("The sum of main diagonal is: %d\n", SD1);
    printf("The sum of second diagonal is: %d\n", SD2);
    printf("The count of 0 in array is: %d\n", SN);
}
int main()
{
    int n;
    printf("Enter the number of elements(n): ");
    scanf("%d", &n);

    int array[n][n];
    enterArray(n, array);
    printArray(n, array);
    Function(n, array);


    return 0;
}
