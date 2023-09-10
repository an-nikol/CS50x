#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    // typically the convert is atoi
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // store the lenght of the string
    int lenght = strlen(input);
    // base case
    if (lenght == 1)
    {
        return (input[0] - 48);
    }
    else
    {
        // convert the last char to an intent
        int last_number = input[lenght - 1] - 48; // the ASCII value of 0 is 48
        //remove last char by moving the null one position to the left
        input[lenght - 1] = '\0';
        // return this value plus 10 times the integer value of the shortened string
        return (last_number + (10 * convert(input)));
    }
}
