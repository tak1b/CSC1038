#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    //check if there are enough inputs
    if (argc == 1) {
        printf("Arguments needed!\n");
        return 0;
    }

    //define arrays
    int arr[10];
    int count = 0;  //stores the count for each odd number

    for (int i = 1; i < argc && i <= 10; i++) {
        arr[i-1] = atoi(argv[i]);

        //check if the number is odd
        if (arr[i-1] % 2 != 0) {
            count++;
        }
    }
    
    //output
    printf("%d\n", count);
}