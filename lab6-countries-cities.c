/*
Author: Takib Islam
This programme willl find the largest city of the country
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for the City
struct City {
    char name[100];
    float size;
};

// Define a structure for the Country
struct Country {
    char name[100];
    struct City cities[3]; // Each country has 3 cities
};

// Function to find the largest city in a country
struct City findLargestCity(struct Country country) {
    struct City largest = country.cities[0]; // Assume first city is largest
    for (int i = 1; i < 3; i++) {
        if (country.cities[i].size > largest.size) {
            largest = country.cities[i]; // Update if we find a larger city
        }
    }
    return largest;
}

int main(int argc, char *argv[]) {
    // Each country has 7 arguments: 1 country + 3 cities + 3 sizes
    int country_count = (argc - 1) / 7;

    struct Country countries[country_count];

    int arg_index = 1; // Start reading from the 2nd argument
    for (int i = 0; i < country_count; i++) {
        // Copy the country name
        strcpy(countries[i].name, argv[arg_index]);
        arg_index++;

        // Read 3 cities for the country
        for (int j = 0; j < 3; j++) {
            strcpy(countries[i].cities[j].name, argv[arg_index]);
            arg_index++;
            countries[i].cities[j].size = atof(argv[arg_index]); // Convert string to float
            arg_index++;
        }
    }

    // For each country, find the largest city and print the result
    for (int i = 0; i < country_count; i++) {
        struct City largest_city = findLargestCity(countries[i]);
        printf("%s: %s\n", countries[i].name, largest_city.name);
    }

    return 0;
}
