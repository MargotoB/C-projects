#include <stdio.h>
#include <stdlib.h>

void enter_array(int n, int array[n]){
    printf("Enter numbers between 1 and 100:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &array[i]);
        while(array[i]>100 || array[i] < 1){
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

void CountingSort(int n, int array[n]){
    int max = 100;
    int count[max+1];
    int output[n];

    for(int i=0; i<= max; i++){
        count[i] = 0;
    }
    for(int i = 0 ; i<n;i++){
        count[array[i]]++;
    }
    for(int i=1; i<= max; i++){
        count[i] += count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for(int i=0; i<n; i++){
        array[i] = output[i];
    }
}

void Function(int n, int array[n]){
    int sum, sum1 = 0;
    int min = array[0];
    int average = array[(n-1)/2];
    int max = array[n-1];
    int count = 0;

    sum = min + average + max;
    float avgSum = (float)sum / 3;
    printf("The average of S1(avgSum) is: %.2f\n", avgSum);

    for(int i = 0;i<n; i++){
        if(i%2==0 || i == 0){
            sum1 +=array[i];
            count++;
        }
    }
    float avgInd = (float)sum1/count;
    printf("The average of S2(avgInd) is: %.2f\n", avgInd);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while(n % 2 == 0){
        printf("You entered a wrong number! Try again!\n");
        scanf("%d", &n);
    }
    int array[n];
    enter_array(n, array);
    print_array(n, array);

    CountingSort(n, array);
    print_array(n, array);
    Function(n,array);

    return 0;
}
