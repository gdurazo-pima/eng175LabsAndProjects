#include <stdio.h> // print

/*
Pseudocode

create struct with car info
ask for car brand, year, price
scan inputs
print car info
*/

int main(void)
{
    typedef struct // structure to store car info
    {
        char brand[20]; // car brand
        int year; // car year
        float price; // car price
    } carInfo;

    carInfo car; // car variable

    printf("Please enter your dream car's brand: ");
    scanf("%s", car.brand);
    printf("Please enter your dream car's year: ");
    scanf("%d", &car.year);
    printf("Please enter your dream car's price: $");
    scanf("%f", &car.price);

    printf("\nHere is your dream car's information!\nBrand: %s\nYear: %d\nPrice: $%.2f", car.brand, car.year, car.price); // prints on separate lines


    return 0;
}