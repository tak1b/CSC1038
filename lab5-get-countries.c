/*
Author: Takib Islam
Get Countries
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// avoiding typing strruct everytime
typedef struct Country Country;

// struct namd country holds key info
struct Country {
    char country[100];
    char capital[100];
    float population;
    int size;
};

// function declarations
void add_country(Country countrys[], int count, char *argv[]);
void print_country(const Country countrys[], int count);

int main(int argc, char *argv[]) {
    int total_countrys = (argc - 1) / 4; // calculate the total number of countries

    // define an array to hold a maximum of 50 countries
    Country countrys[50];

    // add countries and print them
    add_country(countrys, total_countrys, argv);
    print_country(countrys, total_countrys);

    return 0;
}

// function to add all the given countries to the Country structure array
void add_country(Country countrys[], int count, char *argv[]) {
    for (int i = 0; i < count; i++) {
        strcpy(countrys[i].country, argv[i * 4 + 1]);
        strcpy(countrys[i].capital, argv[i * 4 + 2]);
        countrys[i].population = atof(argv[i * 4 + 3]);
        countrys[i].size = atoi(argv[i * 4 + 4]);
    }
}

// function to print the details of each country
void print_country(const Country countrys[], int count) {
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", 
               countrys[i].country, 
               countrys[i].capital, 
               countrys[i].size, 
               countrys[i].population);
    }
}
