#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n][n]){
    printf("Enter numbers between -1000 and 1000.\n");
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j]<-1000 || array[i][j]>1000){
                printf("The number is out of borders. Try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void print_array(int n, int array[n][n]){
    printf("The array is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int new_array_Func(int n, int array[n][n], int new_array[n*n], int K, int L){
    int index=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(array[i][j]<K || array[i][j]>L){
                new_array[index++] = array[i][j];
            }
        }
    }
    return index;
}

void print_new_array(int element, int new_array[element]){
    printf("The new array is: ");
    for(int i=0; i<element; i++){
        printf("%d ", new_array[i]);
    }
    printf("\n");
}

void bubble_sort(int element, int new_array[element]){
    int temp;
    for(int i=0; i<element-1; i++){
        for(int j=i+1; j<element; j++){
            if(new_array[i]>new_array[j]){
                temp=new_array[i];
                new_array[i]=new_array[j];
                new_array[j] = temp;
            }
        }
    }
}

int main()
{
    printf("This program is finding numbers which is not in the interval!\n");
    printf("Margarita Barakova\n");

    int n;
    printf("Enter rows and cols of matrix(n): ");
    scanf("%d", &n);

    int array1[n][n];
    enter_array(n,array1);
    print_array(n, array1);

    int K,L;
    printf("Enter the lower border: ");
    scanf("%d", &K);
    printf("Enter the bigger border: ");
    scanf("%d", &L);

    int new_array1[n*n];
    int element = new_array_Func(n, array1, new_array1, K, L);
    print_new_array(element, new_array1);

    bubble_sort(element, new_array1);
    printf("Array after sorting\n");
    print_new_array(element, new_array1);

    return 0;
}
