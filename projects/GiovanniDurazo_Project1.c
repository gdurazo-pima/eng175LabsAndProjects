#include <stdio.h> // print and scan

int main(void)
{
    double t0 = 28.6; // temp 1
    double t1 = 21.1854; // temp 2
    double s0 = 3.47; // salinity 1
    double s1 = 10; // salinity 2
    double sSamp = 7.734; // given salinity
    double tPred; // predicted temp
    double tCels = 0; // initialized tPred in degrees Celsius
    double sPpt = 0; // initialized sSamp in parts per thousand

    tPred = t0 + (t1 - t0) * ((sSamp - s0) / (s1 - s0)); // equation

    printf("\nThe predicted freezing temperature of water with a salinity\nof %lf percent is %lf degrees Fahrenheit.\n\n", sSamp, tPred); //print
    printf("The predicted freezing temperature of water with a salinity\nof %.2lf percent is %.4lf degrees Fahrenheit.\n\n", sSamp, tPred); //print w fixed decimals

    tCels = ((tPred - 32) * 5) / 9; // calcs tCels from given equation
    sPpt = sSamp * 10; // calcs sPpt from given equation

    printf("The predicted freezing temperature of water with a salinity\nof %.2lf ppt is %.4lf degrees Celsius.", sPpt, tCels); //print w ppt and deg Cels


    return 0;
}