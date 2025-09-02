#include <stdio.h> 

struct Time {
    int Years;
    int monthsSinceLastBirthday;
    int dayYouWereBorn;
    };

int main() {

struct Time s1;

printf("Input your age in years.\n", s1.Years);
scanf("%d", &s1.Years);
printf("Input how many months since your last birthday.\n", s1.monthsSinceLastBirthday);
scanf("%d", &s1.monthsSinceLastBirthday);
printf("Input the day of the month you were born.\n", s1.dayYouWereBorn);
scanf("%d", &s1.dayYouWereBorn);
printf("You are the age %d. It has been %d since your last birthday. You were born on this day %d.", s1.Years, s1.monthsSinceLastBirthday, s1.dayYouWereBorn);

return 0; 
}