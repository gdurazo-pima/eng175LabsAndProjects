#include <stdio.h> // pritn and scan
#include <String.h> // strcmp
#include <stdbool.h> // bool

int main(void)
{
    int num, rem; // number and remainder
    int sum = 0; // initialize the sum
    int i = 1; // index
    char userChoice[4]; // yes or no input
    bool endLoop = false; // for 1st while loop

    while(endLoop == false) // too lazy to make more variables
    {
        printf("Please enter a number:\n");
        scanf("%d", &num);
    
        while (i < num) // run up until i = num because the number itself doesn't count in determining if it's a perfect num
        {
            rem = num % i; // gets remainder
            if (rem == 0) // if i is an int factor of num
            {
                sum = sum + i; // makes the sum var equal to the factor plus any previous factors
                printf("A factor of %d is %d\n", num, i); // shows factors as it goes
            }
            i++; // adds 1 to index
        }

        if (sum == num) // if the divisors add up to the number (e.g. 1+2+3=6) so if it's a perfect number
        {
            printf("The sum of %d's factors (excluding itself) is %d. %d is a perfect number!\n", num, sum, num); // yippee
            num = 0; // reset var bc problems if not
            rem = 0; // reset var bc problems if not
            sum = 0; // reset var bc problems if not
            i = 1; // reset var bc problems if not
        }
        else // if not
        {
            printf("The sum of %d's factors (excluding itself) is %d. %d is not a perfect number.\n", num, sum, num); // lol
            num = 0; // reset var bc problems if not
            rem = 0; // reset var bc problems if not
            sum = 0; // reset var bc problems if not
            i = 1; // reset var bc problems if not
        }

        printf("Do you want to continue? Please enter yes or no.\n"); // ask if continue
        scanf("%s", userChoice);

        if (strcmp(userChoice, "yes") == 0) // if they enter yes
        {
            printf("Let's continue!\n"); // why not
        }
        else // if not
        {
            printf("Thank you for trying my code! See you next time!"); // it doesn't hurt to be nice
            endLoop = true; // stops loop
        }
    }


    return 0;
}