/*
Author: Takib Islam
Sort Countries by Population
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 100

// define the structure to hold country information
typedef struct {
    char name[50];
    char capital[50];
    float population;
    int size;
} Country;

// function to read input and populate the countries array
int read_countries(int argc, char *argv[], Country *countries) {
    int country_count = 0;
    for (int i = 1; i < argc; i += 4) {
        if (country_count >= MAX_COUNTRIES) break;
        
        strcpy(countries[country_count].name, argv[i]);
        strcpy(countries[country_count].capital, argv[i+1]);
        countries[country_count].population = atof(argv[i+2]);
        countries[country_count].size = atoi(argv[i+3]);
        country_count++;
    }
    return country_count;
}

// function to sort countries by population in descending order
void sort_countries_by_population(Country *countries, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (countries[j].population < countries[j + 1].population) {
                // Swap countries[j] and countries[j + 1]
                Country temp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = temp;
            }
        }
    }
}

// function to print the sorted list of countries
void print_sorted_countries(Country *countries, int count) {
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n",
               countries[i].name,
               countries[i].capital,
               countries[i].size,
               countries[i].population);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5 || (argc - 1) % 4 != 0) {
        printf("Usage: %s <Country> <Capital> <Population> <Size> ...\n", argv[0]);
        return 1;
    }

    // array to hold country details
    Country countries[MAX_COUNTRIES];
    
    // read countries from command line args
    int country_count = read_countries(argc, argv, countries);

    // sort countries by population in descending order
    sort_countries_by_population(countries, country_count);

    // print the sorted countries
    print_sorted_countries(countries, country_count);

    return 0;
}
