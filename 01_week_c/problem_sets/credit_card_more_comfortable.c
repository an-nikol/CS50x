#include <cs50.h>
#include <math.h>
#include <stdio.h>

int every_other_digit(long credit_card);
int multiply_and_sum(int last_digit);
int number_of_digits(long credit_card);
bool is_amex(long credit_card, int total_number_of_digits);
bool is_master_card(long credit_card, int total_number_of_digits);
bool is_visa(long credit_card, int total_number_of_digits);

int main(void)
{
    // prompt the user for a credit card number
    long credit_card = get_long("Credit Card: ");
    // calling functions
    int sum_every_other_digit = every_other_digit(credit_card);
    int total_number_digits = number_of_digits(credit_card);
    bool amex = is_amex(credit_card, total_number_digits);
    bool master_card = is_master_card(credit_card, total_number_digits);
    bool visa = is_visa(credit_card, total_number_digits);

    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master_card == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// start with the check-sum part of the problem
// find every_other_digit
int every_other_digit(long credit_card)
{
    // we need only every other digit
    bool is_every_other_digit = false;
    // create a variable to sum every other digit
    int sum = 0;
    // make a while loop to divide the number
    while (credit_card > 0)
    {
        if (is_every_other_digit == true) // getin second to last digits
        {
            // find the last digit by % it by 10
            int last_digit = credit_card % 10;
            // call the multiply function
            int multiply_digits = multiply_and_sum(last_digit);
            sum += multiply_digits;
        }
        else // here we add the numbers that were not initially multipled
        {
            int last_digit = credit_card % 10;
            sum += last_digit;
        }

        // switch true and false to pass a number
        is_every_other_digit = !is_every_other_digit;
        // remove the last digit from the credit card
        credit_card /= 10;
    }
    return sum;
}

// multiply and sum every other number
int multiply_and_sum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum += last_digit_multiply;
        multiply /= 10;
    }
    return sum;
}

int number_of_digits(long credit_card)
{
    int counter = 0;
    while (credit_card > 0)
    {
        counter++;
        credit_card /= 10;
    }
    return counter;
}

bool is_amex(long credit_card, int total_number_of_digits)
{
    // pow to the number of digits minus two
    int first_two_digits = credit_card / pow(10, 13);
    if ((total_number_of_digits == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_master_card(long credit_card, int total_number_of_digits)
{
    int first_two_digits = credit_card / pow(10, 14);
    if ((total_number_of_digits == 16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_visa(long credit_card, int total_number_of_digits)
{
    if (total_number_of_digits == 13)
    {
        int first_digit = credit_card / pow(10, 12);
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (total_number_of_digits == 16)
    {
        int first_digit = credit_card / pow(10, 15);
        if (first_digit == 4)
        {
            return true;
        }
    }
    return false;
}
