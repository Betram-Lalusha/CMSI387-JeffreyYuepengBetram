#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

    int stringLength = 50;

    char age[stringLength];
    char name[stringLength];
    char classYear[stringLength];
    char dayOfBirth[stringLength];
    char yearOfBirth[stringLength];
    char monthOfBirth[stringLength];

    printf("What is your name? \n");
    scanf("%s",name);
    printf("How old are you? \n");
    scanf("%s",age);
    printf("What year are in college? \n");
    scanf("%s",classYear);
    printf("What day were you born? \n");
    scanf("%s",dayOfBirth);
    printf("What month were you born in? \n");
    scanf("%s",monthOfBirth);
    printf("What year were you born in? \n");
    scanf("%s",yearOfBirth);

    printf("\nname: %s \nage: %s \ncollege year %s \nday of birth: %s \nmonth of birth: %s \nyear of birth: %s \n\n", &name, &age, &classYear, &dayOfBirth, &monthOfBirth, &yearOfBirth);
    return 0;

}