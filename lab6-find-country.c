/*
Author: Takib
Find a Country
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxCountries 100
#define sizeLimit 100000


//define struct to hold country info
typedef struct {
    char name[50];
    char capital[50];
    float population;
    int size;
} Country;

//function to read input and populate country arrays
int read_countries(int argc, char *argv[], Country *countries) {
    int country_count = 0;
    for (int i = 1; i < argc; i+=4) {
        if (country_count > maxCountries) break;

        strcpy(countries[country_count].name, argv[i]);
        strcpy(countries[country_count].capital, argv[i+1]);
        countries[country_count].population = atof(argv[i+2]);
        countries[country_count].size = atoi(argv[i+3]);
        country_count++;
    }
    return country_count;
}

//function ti print countries smaller than the size limit defined above
void print_small_countries(Country *countries, int count) {
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < count; i++) {
        if (countries[i].size < sizeLimit) {
            printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n",
                    countries[i].name,
                    countries[i].capital,
                    countries[i].size,
                    countries[i].population);
        }
    }
}

int main(int argc, char*argv[]) {
    if (argc < 5 || (argc - 1) % 4 !=0) {
        printf("wrong input\n");
        return 1;
    }

    //array to hold country details
    Country countries[maxCountries];

    //read countries from command line
    int country_count = read_countries(argc, argv, countries);

    //print countries
    print_small_countries(countries, country_count);
}