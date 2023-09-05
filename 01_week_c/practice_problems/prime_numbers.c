#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // exclude 1 by definition
    if (number <= 1)
    {
        return false;
    }
    // include 2 as the only number that is even and prime
    if (number == 2)
    {
        return true;
    }
    // make a for-loop to check if the numbers are divisible by themselves

    for (int i = 2; i < number; i++) // start from 2 to the num itself
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}
