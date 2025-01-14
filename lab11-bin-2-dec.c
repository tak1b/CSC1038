#include <stdio.h>
#include <stdlib.h>

void binaryToDecimal(int numDigits, char *binaryDigits[], int *result);

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 9) { // Minimum 1 binary digit, maximum 8
        printf("Too many binary digits entered.\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) { // Validate input
        if (argv[i][0] != '0' && argv[i][0] != '1') {
            printf("Only digits 1 and 0 are permitted.\n");
            return 0;
        }
    }

    int decimalResult = 0;
    binaryToDecimal(argc - 1, argv + 1, &decimalResult); // Pass number of digits and digits
    printf("%d\n", decimalResult);

    return 0;
}

void binaryToDecimal(int numDigits, char *binaryDigits[], int *result) {
    *result = 0; // Initialise result
    for (int i = 0; i < numDigits; i++) {
        *result = (*result << 1) + (binaryDigits[i][0] - '0'); // Shift and add
    }
}
