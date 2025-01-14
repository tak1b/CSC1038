#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    //check args
    if (argc != 2) {
        printf("Please provide exactly 1 argument\n");
        return 0;
    }

    //convert each day into integer
    int day = atoi(argv[1]);

    // Use if-else statements to map the number to the corresponding day
    if (day == 1) {
        printf("Sunday\n");
    } else if (day == 2) {
        printf("Monday\n");
    } else if (day == 3) {
        printf("Tuesday\n");
    } else if (day == 4) {
        printf("Wednesday\n");
    } else if (day == 5) {
        printf("Thursday\n");
    } else if (day == 6) {
        printf("Friday\n");
    } else if (day == 7) {
        printf("Saturday\n");
    } else {
        // Print error message for invalid input
        printf("Invalid input! Please enter a number between 1 and 7.\n");
    }

    return 0;
}

