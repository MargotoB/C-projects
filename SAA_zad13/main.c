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

int EvklidFunc(int a, int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

void Function(int n, int array[n]){
    int min, max;
    int foundOdd = 0;
    int foundEven = 0;
    for(int i=0; i<n; i++){
        if(array[i]%2==1){
            if(!foundOdd){
                min=array[i];
                foundOdd = 1;
            } else if(array[i]<min){
                min=array[i];
            }
        }
    }
    printf("The min odd element is: %d\n", min);


    for(int i = 0; i<n; i++){
        if(array[i]%2==0){
            if(!foundEven){
                max=array[i];
                foundEven = 1;
            } else if(array[i]>max){
                max = array[i];
            }
        }
    }
    printf("The max even element is: %d\n", max);

    if(foundEven && foundOdd){
        int result = EvklidFunc(max, min);
        printf("NOD of %d and %d is %d\n", max, min, result);
    } else{
        printf("Can't calc NOD without odd and even numbers!\n");
    }
}


int main()
{
    int n;
    printf("Enter the number of elements(n): ");
    scanf("%d", &n);
    int array[n];

    enter_array(n, array);
    print_array(n,array);

    Function(n, array);

    return 0;
}
