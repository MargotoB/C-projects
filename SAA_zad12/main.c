#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n]){
    printf("Enter numbers:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
        while(array[i]<0){
        printf("You entered a wrong number! Try again!\n");
        scanf("%d", &array[i]);
        }
    }
}

void print_array(int n, int array[n]){
    printf("The array is:\n");
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void compare_and_find_bigger(int n, int arrayA[n], int arrayB[n], int new_array[n]){
    for(int i=0; i<n; i++){
        if(arrayA[i] > arrayB[i]){
            new_array[i] = arrayA[i];
        } else {
            new_array[i] = arrayB[i];
            }
    }
}

void print_new_array(int n, int new_array[n]){
    printf("The new array is:\n");
    for(int i=0; i < n; i++){
        printf("%d ", new_array[i]);
    }
    printf("\n");
}

void sum_new_array(int n, int new_array[n]){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += new_array[i];
    }

    printf("The sum is: %d\n", sum);

    int number;

    if(sum > 99){
        number = sum % 10;
        printf("The last number is: %d\n", number);
    }
    else{
        printf("The sum is under 99!\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of elements of array: ");
    scanf("%d", &n);

    int arrayA[n];
    int arrayB[n];
    int new_array[n];

    enter_array(n, arrayA);
    print_array(n, arrayA);

    enter_array(n, arrayB);
    print_array(n, arrayB);

    compare_and_find_bigger(n, arrayA, arrayB, new_array);
    print_new_array(n, new_array);

    sum_new_array(n, new_array);

    return 0;
}
