/*
 Author: Takib Islam
 Average Population
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typedef to avoid typing 'struct' before Country
typedef struct Country Country;

// country strcuturew with key info
struct Country {
    char name[100];
    char capital[100];
    float population;
    int size;
};

// Function declarations
void add_countries(Country countries[], int length, char *argv[]);
void print_countries(Country countries[], int length);

int main(int argc, char *argv[]) {
    int length = (argc - 1) / 4; // calculates number of countries

    Country countries[50];

    
    add_countries(countries, length, argv);
    print_countries(countries, length);

    return 0;
}

// add countries to the array
void add_countries(Country countries[], int length, char *argv[]) {
    for (int i = 0; i < length; i++) {
        strcpy(countries[i].name, argv[i * 4 + 1]);
        strcpy(countries[i].capital, argv[i * 4 + 2]);
        countries[i].population = atof(argv[i * 4 + 3]);
        countries[i].size = atoi(argv[i * 4 + 4]);
    }
}

// function to print expected output
void print_countries(Country countries[], int length) {
    float total_population = 0.0;
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int i = 0; i < length; i++) {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", 
               countries[i].name, 
               countries[i].capital, 
               countries[i].size, 
               countries[i].population);

        total_population += countries[i].population;
    }

    float average_population = total_population / length;
    printf("Population average: %.2f\n", average_population);
}
