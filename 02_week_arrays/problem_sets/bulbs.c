#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // prompt a user for string
    string text = get_string("Message: ");
  
    // convert text into decimal
    for (int i = 0; i < strlen(text); i++)
    {
        // create a variable to store decimal
        int decimal_num = text[i];

        // create an array of 8 digits to store the chars of the string
        int binary_num[] = {0, 0, 0, 0, 0, 0, 0, 0};

        // make a while-loop
        int j = 0;
        while (decimal_num > 0)
        {
            // each intereger is divided to check for reminder
            binary_num[j] = decimal_num % 2;
            decimal_num /= 2;
            // remove a num with iteration
            j++;
        }
        // reverse the num from left to right
        // BITS_IN_BYTE minus 1 to start counting from 7!
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            // print the result
            print_bulb(binary_num[k]);
        }
        // print to print every binary nunm on a new line to make a Hi symbol.
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
