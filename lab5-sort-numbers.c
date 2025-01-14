#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//declare prototype
void sort_asc(int *list, int x);
void sort_desc(int *list, int x);

int main(int argc, char *argv[]){
    //declare the inputs
    int x = atoi(argv[1]);
    char *order = argv[x + 2];
    int list[x];
    //filling in the array
    for (int i = 0; i < x; i++){
        list[i] = atoi(argv[i + 2]);
    }
    //sets the pointer function
    void(*sorted_function)(int *, int);
    
    //condition to check which function the pointer will be assigned to
    if (strcmp(order, "asc") == 0){
        sorted_function = sort_asc;
    } 
    else if (strcmp(order, "desc") == 0){
        sorted_function = sort_desc;
    } 
    else {
        printf("Invalid sorting\n");
        return 1;
    }
    //calls the pointer function
    sorted_function(list, x);
    
    //prints the sorted numbers
    printf("Sorted numbers: ");
    for (int i = 0; i < x; i++){
        printf("%d", list[i]);
        if (i < x - 1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

//a function to sort asc orders
void sort_asc(int *list, int x){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x - i - 1; j++){
            if (list[j] > list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
        }
        }
    }
}
//a function to sort dsc orders
void sort_desc(int *list, int x){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x - i - 1; j++){
            if (list[j] < list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
        }
        }
    }
}