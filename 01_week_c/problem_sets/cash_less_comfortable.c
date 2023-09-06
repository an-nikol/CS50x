#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // make a do-while loop to prompt the user for cents
    int cents;
    do
    {
        cents = get_int("Change owned: ");
    }
    while (cents < 1);
    // make it less than 1 to remove negative ints
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    // Compare for each coins if it is a quarter, dime etc.
    if (cents >= 25 && cents <= 49)
    {
        quarters++;
    }
    else if (cents >= 50 && cents <= 74)
    {
        quarters += 2;
    }
    else if (cents >= 75 && cents <= 99)
    {
        quarters += 3;
    }
    else if (cents >= 100 && cents <= 124)
    {
        quarters += 4;
    }
    else if (cents >= 125 && cents <= 149)
    {
        quarters += 5;
    }
    else if (cents >= 150 && cents <= 174)
    {
        quarters += 6;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;

    if (cents >= 10 && cents <= 19)
    {
        dimes++;
    }
    else if (cents >= 20 && cents <= 29)
    {
        dimes += 2;
    }
    else if (cents >= 30 && cents <= 39)
    {
        dimes += 3;
    }
    else if (cents >= 40 && cents <= 49)
    {
        dimes += 4;
    }
    else if (cents >= 50 && cents <= 59)
    {
        dimes += 5;
    }
    else if (cents >= 60 && cents <= 69)
    {
        dimes += 6;
    }
    else if (cents >= 70 && cents <= 79)
    {
        dimes += 7;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;

    if (cents >= 5 && cents <= 9)
    {
        nickels++;
    }
    else if (cents >= 10 && cents <= 14)
    {
        nickels += 2;
    }
    else if (cents >= 15 && cents <= 19)
    {
        nickels += 3;
    }
    else if (cents >= 20 && cents <= 24)
    {
        nickels += 4;
    }
    else if (cents >= 25 && cents <= 30)
    {
        nickels += 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    if (cents == 0)
    {
        pennies += 0;
    }
    else if (cents == 1)
    {
        pennies++;
    }
    else if (cents == 2)
    {
        pennies += 2;
    }
    else if (cents == 3)
    {
        pennies += 3;
    }
    else if (cents == 4)
    {
        pennies += 4;
    }
    return pennies;
}
