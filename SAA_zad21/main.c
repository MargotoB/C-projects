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

int Function1(int n, int array[n][n], double newArr[n]){
    int index = 0;
    for(int i=0; i<n;i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += array[i][j];
        }
        newArr[index++] = (double)sum/n;
        printf("The average of row[%d] is %.2lf\n", i+1, newArr[i]);
    }
    return index;
}

void printNewArr(int n, double newArr[n]){
    printf("The new array is:\n");
    for(int i=0; i<n; i++){
        printf("%.2lf ", newArr[i]);
    }
    printf("\n");
}

void BubbleSort(int n, double newArr[n]){
    double temp;
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
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
    double newArray[n];

    enterArray(n, array);
    printArray(n, array);
    Function1(n, array, newArray);
    printNewArr(n, newArray);

    BubbleSort(n, newArray);
    printf("After sorting!\n");
    printNewArr(n, newArray);

    return 0;
}
