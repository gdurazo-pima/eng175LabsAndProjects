#include <stdio.h> // print and scan
#include <math.h> // pi

/*
Pseudocode
void cubCalc(void)
    * insert cub calcs *

void cylHem(int choice)
    if choice = 3
        * insert hem calcs *
    else
        cylCalc

void cylCalc(void)
    * insert cyl calcs *

main
    int choice
    print ask for choice cuboid(1), cylinder(2), or hemisphere(3)
    scan choice

    switch choice
        case 1
            cubCalc
        case 2
            cylHem(2)
        case 3
            cylHem(3)
        default
            not valid lmao

*/

void cubCalc(void);
void cylHem(int choice);
void cylCalc(void);

int main(void)
{
    int choice; // choice from user

    printf("Please enter an option: 1 (Cuboid), 2 (Cylinder), 3 (Hemisphere)\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        cubCalc(); // runs cuboid calcs
        break;
    
    case 2:
        cylHem(choice); // runs cylCalc called in cylHem
        break;

    case 3:
        cylHem(choice); // runs hem calcs
        break;

    default:
        printf("Sorry, that was not a valid option."); // lmao
        break;
    }


    return 0;
}

void cubCalc(void)
{
    printf("Cuboid calculations for a cuboid with sides a, b, and c:\nSurface Area = 2ab + 2bc + 2ac");
}

void cylHem(int choice)
{
    if (choice == 3)
        printf("Hemisphere calculations for a hemisphere of radius r:\nSurface Area = 2(pi)(r)^2\nVolume = (2/3)(pi)(r)^3");
    
    else
        cylCalc();
}

void cylCalc(void)
{
    printf("Cylinder calculations for a cylinder of radius r and height h:\nSurface Area = 2(pi)r(r + h)");
}