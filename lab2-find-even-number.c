#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    //check args
    if (argc == 1) {
        printf("Arguments needed\n");
        return 0;
    }

    //def array
    int arr[10];
    int found_even = 0;

    //loop
    for (int i = 1; i < argc && i <= 10; i++) {
        arr[i-1] = atoi(argv[i]); //convert input to integer


        if (arr[i-1] % 2 == 0) {
            printf("%d - %d\n", i - 1, arr[i-1]);
            found_even = 1;
        }
    }

    if (!found_even) {
        printf("Not found!\n");
    }
    
    return 0;

}