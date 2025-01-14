/* author: takib islam
   lab5-get-a-country.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country Country; //struct create

struct Country 
{
    //initialising strucutr
  char country_name[30];
  char country_capital[30];
  float population;
  int kilometers;
};

int main(int argc, char*argv[])
{

    Country country1; //call strucutrue

    //assinging command line args
    strcpy(country1.country_name, argv[1]); 
    strcpy(country1.country_capital, argv[2]);
    country1.population = atof(argv[3]);
    country1.kilometers = atoi(argv[4]);
  
    //print
    printf("%s\n", country1.country_name);
    printf("%s\n", country1.country_capital);
    printf("%.2f million people\n", country1.population);
    printf("%d km2\n", country1.kilometers);

    return 0;
}