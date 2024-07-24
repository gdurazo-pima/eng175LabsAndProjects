#include <stdio.h> // library for printf and scanf
#include <math.h> // library for math functions

/*
Pseudocode:
double rate = 15.75 -> given
double hrs, wks -> inputted by user
double salYr = 0 -> for yearly salary
double salMo = 0 -> for monthly salary (end goal)

ask for hrs and wks separately
scan for inputs

multiply hrs by wks by rate to get total $$ in year, then divide by 12 to get the avg monthly salary

print result

*/

int main(void) // i dunno but its important lol
{
    double rate = 15.75; // given var for rate
    double hrs; // var for hours worked
    double wks; // var for weeks worked
    double salYr = 0; // initialized var for yearly salary
    double salMo = 0; // initialized var for monthly salary

    printf("Please enter the number of hours worked per week: "); // ask for input
    scanf("%lf", &hrs); // user inputs

    printf("Please enter the number of weeks worked: "); // ask for input
    scanf("%lf", &wks); // user inputs

    salYr = rate * hrs * wks; // calculate yearly salary
    salMo = salYr / 12; // calculate monthly salary
    
    printf("Monthly salary: $%.2lf", salMo); // print monthly salary

    return 0; // i dunno but its important lol


}